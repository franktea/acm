/*
 * 333.cpp
 *
 *  uva 333 - Recognizing Good ISBNs
 *
 *  Created on: Feb 28, 2015
 *      Author: frank
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

using namespace std;

/**
 * 很无聊很无聊的一道题。。。像猜谜语一样才ac。
 * 只能有10个数字，不能多也不能少，最多只能有一个X，并且必须是最后一个。
 * 可能包含空行、但是不包含只有空格和tab键的行；
 * 如果是非法的isbn，必须要将首尾的空格全部去掉，但是中间的保留，然后将这个作为非法的值输出来。
 * @param line
 */

void Check(string& line)
{
    vector<int32_t> isbn;
    size_t p1 = line.find_first_not_of(" \t\n");
    if(p1 == string::npos)
    {
        cout<<line<<" is incorrect.\n"; // 空行
        return;
    }
    size_t p2 = line.find_last_not_of(" \t\n");
    string isbnstr(line, p1, p2-p1+1); // 去掉首尾的空格和tab符号，相当于trim
    cout<<isbnstr<<" ";
    bool found = false;
    struct Tmp
    {
        bool& found_;
        Tmp(bool& found):found_(found) {}
        ~Tmp() { if(!found_) cout<<"is incorrect.\n"; }
    } tmp(found);

    for(char c: isbnstr)
    {
        if(c >= '0' && c<= '9')
        {
            isbn.push_back(c-'0');
            if(isbn.size()>10) return;
        }
        else if(c == 'X')
        {
            isbn.push_back(10);
            if(isbn.size() != 10) return;
        }
        else if(c == '-') // just ignore
        {
            continue;
        }
        else // not valid
        {
            return;
        }
    }

    if(isbn.size() != 10) return;
    int32_t sum1 = isbn[0];
    int32_t sum2 = isbn[0];
    for(size_t i = 1; i < isbn.size(); ++i)
    {
        sum1 += isbn[i];
        sum2 += sum1;
    }
    if(sum2 % 11) return;
    found = true;
    cout<<"is correct.\n";
}

int main()
{
    string line;
    while(std::getline(cin, line))
    {
        Check(line);
    }
    return 0;
}
