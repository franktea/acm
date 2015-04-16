/*
 * 355.cpp
 *
 *  Created on: Mar 2, 2015
 *      Author: frank
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <stdint.h>

using namespace std;

// 355和343是同一种类型，先占坑，有空来解决
// 本题的坑：数据可能会超出int32，所以必须用int64，否则就错了！

class SInt
{
public:
    explicit SInt(string& str, int64_t base): str_(str), base_(base)
    {
        int64_t max_number = 0;
        for(char c: str_)
        {
            max_number = std::max(max_number, ToInt(c));
        }
        min_base_ = ++max_number;
        if(min_base_ < 2) min_base_ = 2; // 最小必须是2，1不算
    }

    string ToBase(int64_t base)
    {
        int64_t value = AsBase(base_);
        string result;
        int64_t quotient; // 商
        int64_t remainder; // 余数
        do {
            quotient = value / base;
            remainder = value % base;
            result.push_back(ToChar(remainder));
            value = quotient;
        } while(quotient != 0);
        std::reverse(result.begin(), result.end());
        return result;
    }

    int64_t MinBase() { return min_base_; }
private:
    int64_t AsBase(int64_t base) // 对应base的值
    {
        int64_t result = 0;
        int64_t b = 1;
        for(int64_t i = str_.size() - 1; i >= 0; --i)
        {
            result += ToInt(str_[i])*b;
            b*=base;
        }
        return result;
    }

    int64_t ToInt(char c)
    {
        return (c >= '0' && c <= '9') ? c-'0' : c-'A'+10;
    }

    char ToChar(int64_t n)
    {
        return n <= 9 ? n + '0' : n + 'A' - 10;
    }
private:
    std::string& str_;
    const int64_t base_;
    int64_t min_base_;
};


int main()
{
    int64_t base1, base2;
    string str;
    while(cin>>base1>>base2)
    {
        cin>>str;
        SInt si(str, base1);
        if(si.MinBase() > base1)
        {
            cout<<str<<" is an illegal base "<<base1<<" number\n";
            continue;
        }
        cout<<str<<" base "<<base1<<" = "<<si.ToBase(base2)<<" base "<<base2<<"\n";
    }
}
