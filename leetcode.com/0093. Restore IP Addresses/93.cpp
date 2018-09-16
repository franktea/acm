/*
 * 93.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 用递归的方法，递归四层，居然是打败100%
// 下次再试试非递归的方法

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.length() > 12 || s.length() < 4) return result_;
        tmp_.resize(4);

        Check(0, 0, s);

        return result_;
    }
private:
    void Check(int depth, int index, const string& s) // depth 为递归层次，index为本次递归从第几个字符开始尝试截取数字
    {
    	if(depth == 4)
    	{
    		if(index == s.length())
    			result_.push_back(tmp_[0] + "." + tmp_[1] + "." + tmp_[2] + "." + tmp_[3]);
    		return;
    	}

    	for(int i = 1; i <= 3; ++i) // 最多截取3个数字
    	{
    		if(index + i > s.length())
    			break;

    		string str = s.substr(index, i);
    		if(std::stoi(str) > 255)
    			break;

    		if(str.length() != 1 && str[0] == '0') // 只有0是一个合法的ip中的一个数字，010不是,001也不是
    			break;

    		tmp_[depth] = str;
    		Check(depth + 1, index + i, s);
    	}
    }
private:
    vector<string> tmp_;
    vector<string> result_;
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	string s = "25525511135";
	vector<string> v = ps->restoreIpAddresses(s);
	for(auto&& s: v)
	{
		cout<<s<<"\n";
	}
	return 0;
}



