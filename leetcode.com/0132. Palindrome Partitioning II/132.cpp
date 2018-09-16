/*
 * 132.cpp
 *
 *  Created on: Sep 14, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// 用131的遍历方法，加了剪枝，但是对于长的字符串case运行会超时。

class Solution {
public:
    int minCut(string s) {
    	if(s.empty())
    		return 0;

    	result_ = std::numeric_limits<int>::max();
    	s_ = &s;
    	indexes_.reserve(s.length());
    	indexes_.push_back(0);
    	DFS(1);
    	return result_;
    }
private:
    void DFS(int i)
    {
    	//cout<<"dfs i="<<i<<"\n";
    	const string& s = *s_;

    	if(i > s.length())
    	{
    		if(indexes_.back() != s.length()) // 最后一个字符没被加进来，表示最后一个子串非回文，直接丢弃此组结果。
    			return;

    		result_ = std::min(int(indexes_.size()) - 2, result_);
    		return;
    	}

    	if(result_ != std::numeric_limits<int>::max() && int(indexes_.size() > result_ + 2)) // 剪枝
    		return;

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
    int result_;
    const string* s_;
    vector<int> indexes_;
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	auto&& result = ps->minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp");
	cout<<"ret="<<result<<"\n";
	return 0;
}


