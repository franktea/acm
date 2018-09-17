/*
 * 152.cpp
 *
 *  Created on: Sep 17, 2018
 *      Author: frank
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 此题最大的技巧是需要在每个位置同时记住正的最大值和负的最小值，
// 因为负的以后遇到负数可能会变成最大的。

// 当a[n] > 0时：f(n) = f(n-1)*a[n]，其中f(n-1) > 0;
//              f(n) = a[n]，其中f(n-1) = 0
// 当a[n] < 0时，原理一样。

class Solution {
	struct MaxValue
	{
		int negative; // 正的最大值
		int positive; // 负的最大值
	};
public:
    int maxProduct(vector<int>& nums) {
    	if(nums.empty())
    		return 0;

    	MaxValue mv;
    	if(nums[0] > 0)
    		mv = {0, nums[0]};
    	else
    		mv = {nums[0], 0};

    	int result = nums[0];
    	for(int i = 1; i < nums.size(); ++i)
    	{
    		MaxValue value = {0, 0};
    		if(nums[i] > 0)
    		{
    			value.positive = std::max(mv.positive * nums[i], nums[i]);
    			value.negative = nums[i] * mv.negative;
    		}
    		else
    		{
    			value.positive = mv.negative * nums[i];
    			value.negative = std::min(nums[i], mv.positive * nums[i]);
    		}
    		mv = value;
    		result = std::max(result, mv.positive);
    	}

    	return result;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<int> v = {-2,0,-1};
	Solution* ps = new Solution;
	int ret = ps->maxProduct(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}

