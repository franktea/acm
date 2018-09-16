/*
 * 151.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 比较恶心的是字符串里面不仅仅有空格，还有标点符号。

class Solution {
public:
    void reverseWords(string &s) {
    	// 删除尾部的空格
    	int index = s.length() - 1;
    	while(index >= 0 && s[index] == ' ')
    		--index;
    	if(index != s.length() - 1)
    	{
    		s.erase(index+1, s.length() - 1 - index);
    	}

    	// 删除前面的空格
    	index = 0;
    	while(index < s.length() && s[index] == ' ')
    		++index;
    	if(index != 0)
    	{
    		s.erase(0, index);
    	}

    	// 去掉中间多余的空格
    	index = 0;
    	while(index <s.size())
    	{
    		if(s[index] == ' ')
    		{
    			int i = index + 1;
    			while(i < s.size() && s[i] == ' ')
    				++i;

    			if(i - index > 1)
    			{
    				s.erase(index+1, i-index-1);
    			}
    		}

    		++index;
    	}

    	std::reverse(s.begin(), s.end());
    	auto is_char = [](char c)->bool{return c != ' ';};
    	auto is_space = [](char c)->bool{return c == ' ';};
    	auto it1 = std::find_if(s.begin(), s.end(), is_char);
    	auto it2 = std::find_if(s.begin(), s.end(), is_space);
    	while(it1 != s.end())
    	{
    		std::reverse(it1, it2);
    		it1 = std::find_if(it2, s.end(), is_char);
    		it2 = std::find_if(it1, s.end(), is_space);
    	}
    }
};
static  int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	string s = "    abc     def    ghijk!!     xyz ";
	Solution* ps = new Solution;
	ps->reverseWords(s);
	cout<<s<<"\n";
	return 0;
}

