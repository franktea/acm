/*
 * 131.cpp
 *
 *  Created on: Sep 14, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 长度为n的串，有n-1个间隙，每个间隙切断还是不切断，共有2^(n-1)种可能性。
// 稍微写一下递归，居然也打败了100%。

class Solution {
public:
    vector<vector<string>> partition(string s) {
    	vector<vector<string>> result;
    	if(s.empty())
    		return result;

    	s_ = &s;
    	indexes_.reserve(s.length());
    	indexes_.push_back(0);
    	result_ = &result;
    	DFS(1);
    	return result;
    }
private:
    void DFS(int i)
    {
    	//cout<<"dfs i="<<i<<"\n";
    	const string& s = *s_;
    	vector<vector<string>>& result = *result_;

    	if(i > s.length())
    	{
    		if(indexes_.back() != s.length()) // 最后一个字符没被加进来，表示最后一个子串非回文，直接丢弃此组结果。
    			return;

    		vector<string> v;
    		for(int x = 1; x < indexes_.size(); ++x)
    		{
    			v.push_back(s.substr(indexes_[x-1], indexes_[x]-indexes_[x-1]));
    		}
    		result.push_back(v);

//    		for(int x: indexes_)
//    			cout<<x<<", ";
//    		cout<<"\n";

    		return;
    	}

    	if(IsPalindrome(s, indexes_.back(), i)) // 如果当前字符和上一个切断位置的字符之间的字符串是回文，则可以增加一个切断
    	{
    		indexes_.push_back(i);
    		DFS(i+1);
    		indexes_.pop_back();
    	}

    	DFS(i+1); // 否则就直接遍历下一个字符
    }

    bool IsPalindrome(const string& s, int i, int j)
    {
    	const char* p1 = &s[0] + i;
    	const char* p2 = &s[0] + j - 1;
    	while(p1 <= p2)
    	{
    		if(*p1++ != *p2--)
    			return false;
    	}
    	return true;
    }
private:
    const string* s_;
    vector<int> indexes_;
    vector<vector<string>>* result_;
};

int main()
{
	Solution* ps = new Solution;
	auto&& result = ps->partition("aabb");
	cout<<"==============================\n";
	for(const vector<string>& v: result)
	{
		for(const string& s: v)
			cout<<s<<", ";
		cout<<"\n";
	}
	return 0;
}



