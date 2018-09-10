/*
 * 40.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

// 用递归的方法求组合，用set来去重
// 用递归的方法，通过了，但是只打败0%的玩家。还有继续减枝优化的空间。也可以尝试非递归的方法

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	std::sort(candidates.begin(), candidates.end()); // 此处一定要先排序，因为题目的输入并不是有序的
    	arr_.resize(candidates.size());
    	Recurve(0, candidates, target);
    	result_.assign(tmp_.begin(), tmp_.end());
    	return result_;
    }
private:
    void Recurve(int depth, const vector<int>& nums, int left) // 递归，对于每个元素，存在“选”和“不选”两种状态，参数left表示距离当前目标和还剩余多少
    {
    	if(depth == arr_.size())
    	{
    		vector<int> v;
    		for(int index = 0; index < arr_.size(); ++index)
    		{
    			if(arr_[index] == 1)
    			{
    				v.push_back(nums[index]);
    			}
    		}
    		if(!v.empty() && left == 0)
    			tmp_.insert(v);

    		return;
    	}

		arr_[depth] = 0;
		Recurve(depth + 1, nums, left);

		if(left < 0) // 减枝，对于当前和已经超过的，直接放弃
			return;

		arr_[depth] = 1;
		Recurve(depth + 1, nums, left - nums[depth]);
    }
private:
    vector<int> arr_;
    set<vector<int>> tmp_;
    vector<vector<int>> result_;
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	vector<int> v = {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,
			30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,
			11,33,10,32,22,13,34,18,12};
	vector<vector<int>> ret = ps->combinationSum2(v, 27);
	for(auto&& vv: ret)
	{
		for(int i: vv)
			cout<<i<<", ";
		cout<<"\n";
	}
	return 0;
}

