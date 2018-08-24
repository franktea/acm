/*
 * 32_Longest_Valid_Parentheses.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: frank
 */

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s)
    {
    	int max_len = 0;
    	int current_len = 0;
    	list<char> q; // work as a queue
    	for(char c: s)
    	{
    		if(c == '(')
    		{
    			q.push_back(c);
    		}
    		else // c == ')'
    		{
    			if(q.back() == '(')
    			{
    				q.pop_back();
    				current_len += 2;
    				max_len = std::max(current_len, max_len);
    			}
    			else // invalid
    			{
    				q.clear();
    				current_len = 0;
    			}
    		}
    	}

    	return max_len;
    }
};

int main()
{
	Solution s;
	assert(s.longestValidParentheses("(()") == 2);
	assert(s.longestValidParentheses(")()())") == 4);
	cout<<s.longestValidParentheses("(()()(()()()")<<"\n";
	return 0;
}
