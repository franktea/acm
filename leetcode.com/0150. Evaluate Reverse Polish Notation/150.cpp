/*
 * 150.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 直接用栈超级简单，注意数字中可能有负数。

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(const string& str: tokens)
        {
        	if(str.length() == 1 && !std::isdigit(str[0]))
        	{
        		int a = s.top();
        		s.pop();
        		int b = s.top();
        		s.pop();
        		if(str == "+")
        			b += a;
        		else if(str == "-")
        			b -= a;
        		else if(str == "*")
        			b *= a;
        		else
        			b /= a;
        		s.push(b);
        	}
        	else
        	{
        		s.push(std::stoi(str));
        	}
        }

        return s.top();
    }
};

int main()
{
	return 0;
}



