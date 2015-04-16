/*
 * ONP.cpp
 *
 *  spoj number 4: ONP - Transform the Expression
 *
 *  Created on: Mar 31, 2015
 *      Author: frank
 */

#include <string>
#include <iostream>
#include <stdint.h>

using namespace std;

int32_t Priority(char c)
{
    switch(c)
    {
    case '+': case '-':
        return 1; break;
    case '*': case '/': case '^':
        return 2; break;
    case '(': case ')':
        return 3; break;
    };

    return -1;
}

// 参考这里的思路：http://blog.kingsamchen.com/archives/637
void Infix2Postfix(const string& str, string& result)
{
    result.clear();
    string str_stack;
    str_stack.reserve(100);
    for(char c: str)
    {
        if(c >= 'a' && c <= 'z')
        {
            result.push_back(c);
        }
        else if(c == '(')
        {
            str_stack.push_back(c);
        }
        else if(c == ')')
        {
            char s = str_stack.back();
            str_stack.pop_back();
            do {
                result.push_back(s);
                s = str_stack.back();
                str_stack.pop_back();
            } while(s != '(');
        }
        else // + = * / ^
        {
            if(str_stack.empty() || str_stack[str_stack.size()-1] == '(' ||
                    Priority(c) > Priority(str_stack[str_stack.size()-1]))
            {
                str_stack.push_back(c);
            }
            else
            {
                result.push_back(c);
                result.push_back(str_stack.back());
                str_stack.pop_back();
            }
        }
    }
    while(! str_stack.empty())
    {
        result.push_back(str_stack.back());
        str_stack.pop_back();
    }
}

int main()
{
    int lines;
    cin>>lines;
    string line;
    string result;
    result.reserve(100);
    while(lines--)
    {
        cin>>line;
        Infix2Postfix(line, result);
        cout<<result<<"\n";
    }
}
