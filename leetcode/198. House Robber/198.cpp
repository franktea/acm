/*
 * 198.cpp
 *
 *  Created on: Sep 14, 2018
 *      Author: frank
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// f(n) = max(f(n-1), f(n-2)+a[n])

class Solution {
public:
    int rob(vector<int>& nums) {
    	if(nums.empty()) return 0;
    	if(nums.size() == 1) return nums.back();
    	if(nums.size() == 2) return std::max(nums[0], nums[1]);

    	int a = nums[0];
    	int b = std::max(nums[0], nums[1]);
    	for(int i = 2; i < nums.size(); ++i)
    	{
    		int v = std::max(b, a+nums[i]);
    		a = b;
    		b = v;
    	}

    	return b;
    }
};

int main()
{
	Solution* ps = new Solution;
	vector<int> nums = {2,7,0,0,0,8};
	int ret = ps->rob(nums);
	cout<<"ret="<<ret<<"\n";
	return 0 ;
}



