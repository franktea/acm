/*
 * 20.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: frank
 */
#include <iostream>
#include <stack>

using namespace std;

// 这么简单的居然都要几次才通过。。。

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;

        stack<char> chars;
        for(char c: s)
        {
        	switch(c)
        	{
        	case '(':
        	case '{':
        	case '[':
        		chars.push(c);
        		break;
        	case ')':
        		if(chars.empty() || chars.top() != '(')
        			return false;
        		chars.pop();
        		break;
        	case '}':
        		if(chars.empty() || chars.top() != '{')
        			return false;
        		chars.pop();
        		break;
        	case ']':
        		if(chars.empty() || chars.top() != '[')
        			return false;
        		chars.pop();
        		break;
        	}
        }

        return chars.empty();
    }
};

int main()
{
	return 0;
}


