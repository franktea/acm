/*
 * 43.cpp
 *
 *  Created on: Sep 9, 2018
 *      Author: frank
 */
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 用的是将数字从左右反序，计算完了再将结果反序的方法

class Solution {
public:
    string multiply(string num1, string num2) {
    	if(num1.empty() || num2.empty()) return "0";
    	if(num1[0] == '0' || num2[0] == '0') return "0";

    	std::reverse(num1.begin(), num1.end());
    	std::reverse(num2.begin(), num2.end());

    	if(num2.length() > num1.length())
    		std::swap(num1, num2);
    	vector<vector<int>> tmp;
    	for(size_t index = 0; index < num2.size(); ++index)
    	{
    		vector<int> v;
    		v.reserve(index + num1.size() + 1);
    		for(size_t x = 0; x < index; ++x)
    			v.push_back(0);

    		int left = 0; // 进位数
    		for(char c: num1)
    		{
    			int a = c - '0';
    			int b = num2[index] - '0';
    			int value = a * b + left;
    			v.push_back(value % 10);
    			left = value / 10;
    		}
    		if(left > 0)
    			v.push_back(left);

    		tmp.push_back(v);
    	}

    	// 将每个vector拉伸成一样的长度，在末尾填上0，做加法的时候就简单了。
    	size_t max_length = tmp[0].size();
    	for(auto&& v: tmp)
    		max_length = std::max(max_length, v.size());
    	for(auto&& v: tmp)
    		v.resize(max_length, 0);

//    	for(auto&& v: tmp)
//    	{
//    		for(int i: v)
//    		{
//    			cout<<i<<", ";
//    		}
//    		cout<<"\n";
//    	}

    	// 做加法
    	vector<int> v_sum;
    	v_sum.reserve(max_length + 1);
    	{
    		int left = 0;
    		for(size_t index = 0; index < max_length; ++index)
    		{
    			int s = 0;
    			for(auto&& v: tmp)
    			{
    				s += v[index];
    			}
    			s += left;
    			v_sum.push_back(s % 10);
    			left = s / 10;
    		}
    		while(left > 0)
    		{
    			v_sum.push_back(left % 10);
    			left /= 10;
    		}
    	}

//    	cout<<"===================\n";
//    	for(int i: v_sum)
//    		cout<<i<<",";
//    	cout<<"\n";

    	std::reverse(v_sum.begin(), v_sum.end());
    	string result;
    	result.reserve(v_sum.size());
    	for(int i: v_sum)
    		result.push_back('0' + i);

    	return result;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution s;
	string ret = s.multiply("12345", "983");
	cout<<"ret="<<ret<<"\n";
	return 0;
}



