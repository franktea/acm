/*
 * 10.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 用递归的方法。递归的深度就是模式的个数。
// 将模式分组，每次递归一个模式，按照每个模式可以匹配的全部字符向后移动字符的位置，
// 如果匹配到最后，模式和字符都用完，则说明匹配成功。

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<string> patterns; // 将所有的pattern分离出来
        for(int index = p.size() - 1; index >= 0; ) // 倒着解析
        {
        	if(p[index] == '*')
        	{
        		patterns.push_back(p.substr(index-1, 2));
        		--index;
        	}
        	else
        	{
        		patterns.push_back(p.substr(index, 1));
        	}
        	--index;
        }
        std::reverse(patterns.begin(), patterns.end()); // 再反序

//        for(auto&& s: patterns)
//        	cout<<s<<"\n";

        return Recurse(s, patterns, 0, 0);
    }
private:
    bool Recurse(const string& s, const vector<string>& patterns, const int index, const int pos)
    {
//    	cout<<"index="<<index<<", pos="<<pos<<"\n";
    	if(index == patterns.size() && pos == s.size())
    		return true;

    	// 如果字符串已经匹配完成，但是剩下的模式都是以*结尾，则也算匹配成功
    	if(pos >= s.size() && index < int(patterns.size()))
    	{
    		if(std::all_of(patterns.begin() + index, patterns.end(), [](const string& str){ return str.back() == '*';}))
    			return true;
    	}

    	if(pos >= s.size() || index >= patterns.size())
    		return false;

    	const string& pattern = patterns[index];
    	if(pattern.size() == 1) // 不含*
    	{
    		if(pattern[0] == '.' || pattern[0] == s[pos])
    		{
    			return Recurse(s, patterns, index + 1, pos + 1);
    		}
    		else // 单个字符，不匹配
    			return false;
    	}
    	else // 含有*
    	{
    		if(pattern[0] == '.') // 任意字符
    		{
    			for(int i = 0; i <= int(s.length()) - pos; ++i)
    				if(Recurse(s, patterns, index + 1, pos + i))
    					return true;
    		}
    		else // 普通字符
    		{
    			int next_different = pos;
    			while(next_different < s.length() && s[next_different] == pattern[0])
    				++next_different;

    			for(int i = 0; i <= next_different - pos; ++i)
    				if(Recurse(s, patterns, index + 1, pos + i))
    					return true;
    		}
    	}

    	return false;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	bool ret = ps->isMatch("a", "ab*");
	cout<<"ret="<<ret<<"\n";
	return 0;
}


