/*
 * 44.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
    	string p2; // 将所有连续的*合成一个，否则会超时
    	for(char c: p)
    	{
    		if(c == '*' && !p2.empty() && p2.back() == '*')
    			continue;

    		p2.push_back(c);
    	}
        return Recurse(s, p2, 0, 0);
    }
private:
    bool Recurse(const string& s, const string& patterns, const int index, const int pos)
    {
    	if(index == patterns.size() && pos == s.size())
    		return true;

    	// 如果字符串已经匹配完成，但是剩下的模式都是以*结尾，则也算匹配成功
    	if(pos >= s.size() && index < int(patterns.size()))
    	{
    		if(std::all_of(patterns.begin() + index, patterns.end(), [](const char& c){ return c == '*';}))
    			return true;
    	}

		if(pos >= s.size() || index >= patterns.size())
			return false;

		const char pattern = patterns[index];
		if(pattern == '?') // 匹配一个字符
		{
			if(Recurse(s, patterns, index + 1, pos + 1)) // 匹配1个字符
				return true;
		}
		else if(pattern == '*') // 匹配任意字符
		{
			for(int i = 0; i <= int(s.length()) - pos; ++i)
			{
			    if(Recurse(s, patterns, index + 1, pos + i))
			    	return true;
			}
		}
		else // 匹配普通字符
		{
			// 将模式中当前普通字符后面的所有连续的普通字符全部找出来，一次性匹配
			int next_special = index + 1;
			while(next_special < patterns.size() && patterns[next_special] != '*' && patterns[next_special] != '?')
				++next_special;

			if(int(s.length()) - pos < next_special - index)
				return false;

			for(int i = 0; i < next_special - index; ++i)
				if(pos + i < s.length() && s[pos + i] != patterns[index + i])
					return false;

			return Recurse(s, patterns, next_special, pos + next_special - index);
		}

    	return false;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	bool ret = ps->isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
			"**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");
	//bool ret = ps->isMatch("a", "ab*");
	//cout<<"ret="<<ret<<"\n";
	return 0;
}

