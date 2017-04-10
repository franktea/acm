/*
 * 843.cpp
 *  uva 843 - Crypt Kicker
 *  Created on: Apr 10, 2017
 *      Author: franktang
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <algorithm>
#include <stdint.h>
#include <stdlib.h>

using namespace std;

void split(const std::string& str, const std::string& delimiters,
        std::vector<std::string>& tokens)
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while(string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

class Dict
{
    friend class Guess;
public:
    Dict(int32_t length) { all_words.reserve(length); }
    void AddWord(const string& word)
    {
        all_words.push_back(word);
    }

    void FinishAdding()
    {
        std::sort(all_words.begin(), all_words.end(), [](const string& lhs, const string& rhs)
                {
                    return lhs.size() > rhs.size();
                });
    }
private:
    vector<string> all_words;
};

class Guess
{
public:
    Guess(const Dict& d, const string& s):
        dict(d), sentence(s)
    {
        split(sentence, " ", secrets);
        std::sort(secrets.begin(), secrets.end(), [](const string& lhs, const string& rhs)
                {
                    return lhs.size() > rhs.size();
                });
        bzero(sec2ori, sizeof(sec2ori));
        bzero(ori2sec, sizeof(ori2sec));
    }

    bool CheckWord(const string& secret, const string& original,
            std::map<char, char>& delta_map)
    {
        for(size_t i = 0; i < secret.size(); ++i)
        {
            char sec = secret[i];
            char ori = original[i];

            if(sec2ori[sec-'a'] != 0)
            {
                if(sec2ori[sec-'a'] != ori)
                    return false;
                else
                    continue;
            }

            // now sec2ori[sec-'a'] is 0
            auto it = delta_map.find(sec);
            if(it == delta_map.end())
            {
                if(ori2sec[ori-'a'] != 0)
                {
                    return false;
                }

                delta_map[sec] = ori;
            }
            else // added this time
            {
                if(it->second != ori)
                    return false;
            }
        }

        for(auto it = delta_map.begin(); it != delta_map.end(); ++it)
        {
            sec2ori[it->first - 'a'] = it->second;
            ori2sec[it->second - 'a'] = it->first;
        }
        return true;
    }

    void Find(size_t index, bool& found)
    {
        if(index >= secrets.size())
        {
            found = true;
            for(char c: sentence)
            {
                if(c == ' ')
                    cout<<c;
                else
                    cout<<sec2ori[c-'a'];
            }
            cout<<"\n";
            return;
        }

        for(size_t i = 0; i < dict.all_words.size() && ! found; ++i)
        {
            if(secrets[index].size() < dict.all_words[i].size())
                continue;
            if(secrets[index].size() > dict.all_words[i].size())
                break;

            map<char, char> delta_map;
            if(CheckWord(secrets[index], dict.all_words[i], delta_map))
            {
                Find(index+1, found);
                if(! found) // cancel something
                {
                    for(auto it = delta_map.begin(); it != delta_map.end(); ++it)
                    {
                        sec2ori[it->first - 'a'] = 0;
                        ori2sec[it->second - 'a'] = 0;
                    }
                }
                else
                {
                    return;
                }
            }
        }
    }

    void Solve()
    {
        bool found = false;
        Find(0, found);
        if(! found)
        {
            for(auto c: sentence)
            {
                if(c == ' ')
                    cout<<c;
                else
                    cout<<'*';
            }
            cout<<"\n";
        }
    }
private:
    const Dict& dict;
    const string& sentence;
    vector<string> secrets;
    char sec2ori[26];
    char ori2sec[26];
};

int main()
{

    string line;
    std::getline(cin, line);
    int32_t wc = atoi(line.c_str());
    Dict dict(wc);
    while(wc--)
    {
        std::getline(cin, line);
        dict.AddWord(line);
    }
    dict.FinishAdding();

    while(std::getline(cin, line))
    {
        if(line.size() == 0)
            continue;

        Guess guess(dict, line);
        guess.Solve();
    }
    return 0;
}



