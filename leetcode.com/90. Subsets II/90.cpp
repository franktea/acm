/*
 * 90.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 用递归的方法求组合，用set来去重。实现简单，但是性能一般

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	std::sort(nums.begin(), nums.end()); // 此处一定要先排序，因为题目的输入并不是有序的
    	arr_.resize(nums.size());
    	Recurve(0, nums);
    	result_.assign(tmp_.begin(), tmp_.end());
    	return result_;
    }
private:
    void Recurve(int depth, const vector<int>& nums) // 递归，对于每个元素，存在“选”和“不选”两种状态
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
    		tmp_.insert(v);

    		return;
    	}

    	for(int i = 0; i <= 1; ++i)
    	{
    		arr_[depth] = i;
    		Recurve(depth + 1, nums);
    	}
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
	vector<int> v = {1,2,2};
	vector<vector<int>> ret = ps->subsetsWithDup(v);
	for(const vector<int>& vv: ret)
	{
		for(int i: vv)
			cout<<i<<", ";
		cout<<"\n";
	}
	return 0;
}

