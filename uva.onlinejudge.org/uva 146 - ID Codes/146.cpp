/*
 * 146.cpp
 *
 *  http://uva.onlinejudge.org/external/1/146.html
 *
 *  title: ID Codes
 *  Created on: Feb 4, 2015
 *      Author: franktang
 */

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <stddef.h>
#include <string>

using namespace std;

/**
 * 就是想试试next_permutation算法，经过测试发现即使序列中含有重复的元素也可以正确得出结果
 */
void Next(string& line)
{
    if(next_permutation(line.begin(), line.end()))
    {
        cout<<line<<"\n";
    }
    else
    {
        cout<<"No Successor\n";
    }
}

int main()
{
    string line;
    while(std::getline(cin, line))
    {
        if(line == "#") break;
        Next(line);
    }
    return 0;
}

