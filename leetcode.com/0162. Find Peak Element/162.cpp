/*
 * 162.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>

using namespace std;

// 不知道这个题的通过率为何那么低，本以为有什么陷阱呢，结果居然是最简单的。
// 加不加fast都只打败98%，看来还有优化空间。

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()) return -1;
        if(nums.size() == 1) return 0;

        for(int i = 0; i < nums.size(); ++i)
        {
        	if(i == 0 && i == nums.size()-1)
        		return i;

        	if(i == 0)
        	{
        		if(nums[i] > nums[i+1])
        			return i;
        	}
        	else if(i == nums.size() - 1)
        	{
        		if(nums[i] > nums[i-1])
        			return i;
        	}
        	else
        	{
        		if(nums[i] > nums[i+1] && nums[i] > nums[i-1])
        			return i;
        	}
        }

        return -1;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	vector<int> v = {1,2,1,3,5,6,4};
	int ret = ps->findPeakElement(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



