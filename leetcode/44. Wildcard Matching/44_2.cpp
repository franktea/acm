/*
 * 44_2.cpp
 *
 *  Created on: Sep 13, 2018
 *      Author: frank
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

// 还是用递归的方法，通过了，虽然用了hashset来保存状态，但是效率仍然不高。

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

class Solution {
public:
    bool isMatch(string s, string p) {
    	if(p.empty()) return s.empty();

    	vector<string> patterns; // 将所有的pattern全部分拆，连续的*合并成一个，连续的？和连续的字符都当成一个整串分拆
    	for(char c: p)
    	{
    		if(patterns.empty())
    		{
    			patterns.push_back(string(1, c));
    			continue;
    		}

    		if(c == '*')
    		{
    			if(patterns.back()[0] != '*')
    				patterns.push_back(string(1, '*'));
    		}
    		else if(c == '?')
    		{
    			if(patterns.back()[0] != '?')
    				patterns.push_back(string(1, '?'));
    			else
    				patterns.back().push_back('?');
    		}
    		else if(std::isalpha(c))
    		{
    			if(!std::isalpha(patterns.back()[0]))
    				patterns.push_back(string(1, c));
    			else
    				patterns.back().push_back(c);
    		}
    	}

//    	for(auto&& s: patterns)
//    		cout<<s<<"\n";

    	visited_.clear();

    	return DFS(patterns, s, 0, 0);

    	return true;
    }
private:
    bool DFS(const vector<string>& patterns, const string& s, int i, int j)
    {
//    	cout<<"i,j:"<<i<<", "<<j<<"\n";
    	if(i >= patterns.size() && j >= s.length())
    		return true;

    	if(j >= s.length() && patterns.size() == 1)
    		return patterns.back()[0] == '*';

    	if(i >= patterns.size())
    		return false;

    	bool result = false;

    	const string& p = patterns[i];
    	if(p[0] == '*')
    	{
    		for(int x = 0; j + x <= s.length(); ++x)
    		{
    			auto it = visited_.find(std::pair<int, int>{i+1, j+x});
    			if(it == visited_.end())
    			{
    				result = DFS(patterns, s, i+1, j+x);
    				if(! result)
    					visited_.insert(std::pair<int, int>{i+1, j+x});
    				else
    					return result;
    			}
    		}
    	}
    	else if(p[0] == '?')
    	{
    		if(j + p.size() > s.length())
    			return false;

    		auto it = visited_.find(std::pair<int, int>{i+1, j+p.size()});
    		if(it == visited_.end())
    		{
    			result = DFS(patterns, s, i+1, j+p.size());
    			if(!result)
    				visited_.insert(std::pair<int, int>{i+1, j+p.size()});
    		}
    	}
    	else // string
    	{
    		if(j + p.size() > s.length())
    			return false;

    		if(p != s.substr(j, p.size()))
    			return false;

    		auto it = visited_.find(std::pair<int, int>{i+1, j+p.size()});
    		if(it == visited_.end())
    		{
    			result = DFS(patterns, s, i+1, j+p.size());
    			if(!result)
    				visited_.insert(std::pair<int, int>{i+1, j+p.size()});
    		}
    	}

    	return result;
    }
private:
    std::unordered_set<std::pair<int, int>, pairhash> visited_;
};
static int fast=[](){ios::sync_with_stdio();cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	bool ret = ps->isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
			"**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");
//	bool ret = ps->isMatch("adceb", "*a*b");
//	bool ret = ps->isMatch("zacabz", "*a?b*");
	cout<<"ret="<<ret<<"\n";
	return 0;
}



