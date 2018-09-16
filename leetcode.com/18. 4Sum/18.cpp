/*
 * 18.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: frank
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// 用的是最简单的方法，需要优化

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	std::sort(nums.begin(), nums.end());

    	vector<vector<int>> result;
    	std::set<vector<int>> existed;

    	for(int i = 0; i < nums.size(); ++i)
    	{
    		for(int j = i + 1; j < nums.size(); ++j)
    		{
    			for(int k = j + 1; k < nums.size(); ++k)
    			{
    				int v = nums[i] + nums[j] + nums[k];
    				v = target - v;
    				if(std::binary_search(nums.begin() + k + 1, nums.end(), v))
    				{
    					vector<int> tmp = {nums[i],nums[j],nums[k],v};
    					if(existed.find(tmp) != existed.end())
    						continue;

    					result.push_back(tmp);
    					existed.insert(tmp);
    				}
    			}
    		}
    	}

    	return result;
    }
};

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

int main()
{
	Solution s;
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	vector<vector<int>> ret = s.fourSum(nums, 0);
	for(const vector<int>& v: ret)
	{
		for(int i: v)
		{
			cout<<i<<", ";
		}
		cout<<"\n";
	}

	return 0;
}
