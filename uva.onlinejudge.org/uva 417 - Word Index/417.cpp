/*
 * 417.cpp
 *
 *  Created on: Apr 13, 2017
 *      Author: franktang
 */

#include <iostream>
#include <map>
#include <string>
#include <stdint.h>

using namespace std;

class MapGen
{
public:
    const std::map<string, int32_t>& Map()
    {
        return words_;
    }

    void Generate()
    {
        Gen1();
        Gen2();
        Gen3();
        Gen4();
        Gen5();
        int32_t index = 0;
        for(auto it = words_.begin(); it != words_.end(); ++it)
        {
            it->second = ++index;
        }
    }
private:
    void Gen1()
    {
        for(char c = 'a'; c <= 'z'; ++c)
        {
            string s(4, ' ');
            s.append(1, c);
            words_.insert(std::make_pair(s, 0));
        }
    }

    void Gen2()
    {
        for(char c1 = 'a'; c1 <= 'z'; ++c1)
            for(char c2 = c1+1; c2 <= 'z'; ++c2)
            {
                string s(3, ' ');
                s.append(1, c1);
                s.append(1, c2);
                words_.insert(std::make_pair(s, 0));
            }
    }

    void Gen3()
    {
        for(char c1 = 'a'; c1 <= 'z'; ++c1)
            for(char c2 = c1+1; c2 <= 'z'; ++c2)
                for(char c3 = c2+1; c3 <= 'z'; ++c3)
                {
                    string s(2, ' ');
                    s.append(1, c1);
                    s.append(1, c2);
                    s.append(1, c3);
                    words_.insert(std::make_pair(s, 0));
                }
    }

    void Gen4()
    {
        for(char c1 = 'a'; c1 <= 'z'; ++c1)
            for(char c2 = c1+1; c2 <= 'z'; ++c2)
                for(char c3 = c2+1; c3 <= 'z'; ++c3)
                    for(char c4 = c3+1; c4 <= 'z'; ++c4)
                    {
                        string s(1, ' ');
                        s.append(1, c1);
                        s.append(1, c2);
                        s.append(1, c3);
                        s.append(1, c4);
                        words_.insert(std::make_pair(s, 0));
                    }
    }

    void Gen5()
    {
        for(char c1 = 'a'; c1 <= 'z'; ++c1)
            for(char c2 = c1+1; c2 <= 'z'; ++c2)
                for(char c3 = c2+1; c3 <= 'z'; ++c3)
                    for(char c4 = c3+1; c4 <= 'z'; ++c4)
                        for(char c5 = c4+1; c5 <= 'z'; ++c5)
                    {
                        string s(1, c1);
                        s.append(1, c2);
                        s.append(1, c3);
                        s.append(1, c4);
                        s.append(1, c5);
                        words_.insert(std::make_pair(s, 0));
                    }
    }
private:
    std::map<string, int32_t> words_;
};

int main()
{
    MapGen mg;
    mg.Generate();
    auto& mp = mg.Map();
    string line;
    while(cin>>line)
    {
        string value("     ");
        for(size_t i = 0; i < line.size(); ++i)
        {
            value[value.size() - line.size() + i] = line[i];
        }
        auto it = mp.find(value);
        if(it == mp.end())
        {
            cout<<"0\n";
        }
        else
        {
            cout<<it->second<<"\n";
        }
    }
    return 0;
}


