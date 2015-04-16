/*
 * 344.cpp
 *
 *  title : Roman Digititis
 *
 *  Created on: Feb 2, 2015
 *      Author: franktang
 */

#include <iostream>
#include <string>
#include <strings.h> // for bzero
#include <stdint.h>

using namespace std;

// 个位：i ii iii iv v vi vii viii ix
std::string roman10[] = {"", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix"};
// 十位: x xx xxx xl l lx lxx lxxx xc
std::string roman100[] = {"", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc"};
// 百位: c cc ccc
std::string roman1000[] = {"", "c", "cc", "ccc", "", "", "", "", "", ""};

// 100以内的阿拉伯数字转化为罗马数字的函数
// 100以内的罗马数字，1,5,10,50,100 分别对应 i, v, x, l, c
std::string Arabic2Roman(uint32_t number)
{
    std::string result;
    result.reserve(10);
    result.append(roman1000[number % 1000 / 100]); // 百位
    result.append(roman100[number % 100 / 10]); // 十位
    result.append(roman10[number % 10]); // 个位
    return result;
}

struct TotalCount
{
    uint32_t icount;
    uint32_t vcount;
    uint32_t xcount;
    uint32_t lcount;
    uint32_t ccount;
};

TotalCount arr_total[101];

void FillTotalCount()
{
    bzero(arr_total, sizeof(TotalCount)*101);
    for(uint32_t i = 1; i < 101; ++i)
    {
        string roman = Arabic2Roman(i);
        for(size_t index = 0; index < roman.size(); ++index)
        {
            const char& c = roman[index];
            switch(c)
            {
            case 'i':
                ++ arr_total[i].icount;
                break;
            case 'v':
                ++ arr_total[i].vcount;
                break;
            case 'x':
                ++ arr_total[i].xcount;
                break;
            case 'l':
                ++ arr_total[i].lcount;
                break;
            case 'c':
                ++ arr_total[i].ccount;
                break;
            }
        }
        arr_total[i].icount += arr_total[i - 1].icount;
        arr_total[i].vcount += arr_total[i - 1].vcount;
        arr_total[i].xcount += arr_total[i - 1].xcount;
        arr_total[i].lcount += arr_total[i - 1].lcount;
        arr_total[i].ccount += arr_total[i - 1].ccount;
    }
}

int main()
{
    FillTotalCount();
    uint32_t number;
    while(cin>>number)
    {
        if(0 == number) break;
        printf("%u: %u i, %u v, %u x, %u l, %u c\n", number,
                arr_total[number].icount, arr_total[number].vcount,
                arr_total[number].xcount, arr_total[number].lcount,
                arr_total[number].ccount);
    }
    return 0;
}
