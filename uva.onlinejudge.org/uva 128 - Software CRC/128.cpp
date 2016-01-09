/*
 * 128.cpp
 *
 *  Created on: Jan 10, 2016
 *      Author: frank
 */

#include <iostream>
#include <string>
#include <stdint.h>
#include <string.h>
#include <iomanip>
using namespace std;

const uint32_t g = 34943;

void Solve(const string& str)
{
    uint32_t num = 0;
    for(size_t i = 0; i < str.length(); ++i)
    {
        num = num * 256 + static_cast<uint32_t>(str[i]);
        num %= g;
    }

    num = num * 256 * 256 % g;
    uint32_t ans = (g - num) % g;
    cout<<std::hex<<std::uppercase<<std::setw(2)<<std::setfill('0')<<(ans/256)<<" "<<std::setw(2)<<(ans%256)<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    string str;
    while(std::getline(std::cin, str))
    {
        if(str == "#") break;
        Solve(str);
    }
    return 0;
}



