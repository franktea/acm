/*
 * 15.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: frank
 */
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <set>

using namespace std;

// 三重循环的方法，通过了但是性能不高

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> result;

    	std::sort(nums.begin(), nums.end());

    	std::set<vector<int>> existed;

    	for(size_t i = 0; i + 2 < nums.size(); ++i) // 第一个加数
    	{
    		if(nums[i] > 0) break;
    		for(size_t j = i+1; j + 1 < nums.size(); ++j) // 第二个加数
    		{
    			int v = 0 - nums[i] - nums[j];
    			if(v < nums[j])
    				break;

    			//cout<<"i="<<nums[i]<<",j="<<nums[j]<<"v="<<v<<"\n";
    			if(binary_search(nums.begin()+j+1, nums.end(), v)) // 查找第三个加数是否存在
    			{
    				vector<int> tmp = {nums[i], nums[j], v};
    				if(existed.find(tmp) != existed.end())
    					continue;

    				result.push_back(vector<int>{nums[i], nums[j], v});
    				existed.insert(tmp);
    			}
    		}

    		while(i + 3 <nums.size() && nums[i+1] == nums[i]) // 跳过相同的，算是一点优化
    			++i;
    	}

    	return result;
    }
};

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

int main()
{
	Solution s;
	vector<int> nums = // {13,4,-6,-7,-15,-1,0,-1,0,-12,-12,9,3,-14,-2,-5,-6,7,8,2,-4,6,-5,-10, -4,-9,-14,-14,12,-13,-7,3,7,2,11,7,9,-4,13,-6,-1,-14,-12,9,9,-6,-11, 10,-14,13,-2,-11,-4,8,-6,0,7,-12,1,4,12,9,14,-4,-3,11,10,-9,-8,8,0, -1,1,3,-15,-12,4,12,13,6,10,-4,10,13,12,12,-2,4,7,7,-15,-4,1,-15,8,5, 3,3,11,2,-11,-12,-14,5,-1,9,0,-12,6,-1,1,1,2,-3};
			{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	vector<vector<int>> ret = s.threeSum(nums);
	for(const vector<int>& v: ret)
	{
		for(int i: v)
			cout<<i<<", ";
		cout<<"\n";
	}
	return 0;
}



