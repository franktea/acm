/*
 * 494.cpp
 *
 *  494 - Kindergarten Counting Game
 *
 *  Created on: Mar 3, 2015
 *      Author: frank
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
#include <stdint.h>
#include <ctype.h>

// 超级简单的一个，不过ac了结果是在1.7w名以后

using namespace std;
using namespace std::placeholders;

int main()
{
    //auto f = [](char c){ return 0 != isalpha(c); };

    // 这个地方的isalpha必须要加::，否则编译器会认为是c++里面的isalpha，那个是有2个参数的
    auto f = std::bind(::isalpha, _1);
    string line;
    while(std::getline(cin, line))
    {
        int32_t count = 0;
        auto it = std::find_if(line.begin(), line.end(), f);
        while(it != line.end())
        {
            ++ count;
            it = std::find_if_not(it, line.end(), f);
            it = std::find_if(it, line.end(), f);
        }
        cout<<count<<"\n";
    }

    return 0;
}
