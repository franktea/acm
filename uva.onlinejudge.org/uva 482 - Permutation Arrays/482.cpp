/*
 * 482.cpp
 *
 *  Created on: Jun 23, 2017
 *      Author: franktang
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdint.h>
#include <string>

using namespace std;

void split(const std::string& str, const std::string& delimiters,
    std::vector<std::string>& tokens)
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

struct Item
{
    int32_t index;
    string data;
};


void Solve()
{
    string line;
    std::getline(cin, line);
    vector<string> string_indexes;
    split(line, " ", string_indexes);
    std::getline(cin, line);
    vector<string> string_data;
    split(line, " ", string_data);

    vector<Item> result;
    for(size_t i = 0; i < string_indexes.size(); ++i)
    {
        result.push_back({atoi(string_indexes[i].c_str()), string_data[i]});
    }

    sort(result.begin(), result.end(), [](const Item& lhs, const Item& rhs)
            {return lhs.index < rhs.index;});

    for(auto i: result)
    {
        cout<<i.data<<"\n";
    }
}

int main()
{
    string line;
    std::getline(cin, line);
    int32_t count = atoi(line.c_str());
    for(int32_t i = 0; i < count; ++i)
    {
        std::getline(cin, line); // skip empty line
        if(i > 0) cout<<"\n";
        Solve();
    }
    return 0;
}



