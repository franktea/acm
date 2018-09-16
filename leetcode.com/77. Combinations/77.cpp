/*
 * 77.cpp
 *
 *  Created on: Sep 9, 2018
 *      Author: frank
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 用全排列的方法实现组合，用[1, 1, 1, ..., 0, 0, 0]，其中k个1，n-k个0，来表示从n个元素中选择k个

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
    	vector<vector<int>> result;
    	if(k <= 0) return result;
    	if(n < k) return result;

    	vector<int> tmp;
    	for(int i = k+1; i <= n; ++i)
    	{
    		tmp.push_back(0);
    	}
    	for(int i = 1; i <= k; ++i)
    	{
    		tmp.push_back(1);
    	}

    	set<vector<int>> all_results;
    	do {
    		vector<int> line;
    		line.reserve(k);
    		for(int index = 0; index < tmp.size(); ++index)
    		{
    			if(tmp[index])
    				line.push_back(index + 1);
    		}
    		all_results.insert(line);
    	} while(std::next_permutation(tmp.begin(), tmp.end()));

    	result.assign(all_results.begin(), all_results.end());
    	return result;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	auto&& ret = ps->combine(4, 2);
	for(const vector<int>& v: ret)
	{
		for(int i: v)
			cout<<i<<", ";
		cout<<"\n";
	}
	return 0;
}



