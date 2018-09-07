/*
 * 53.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: frank
 */
#include <vector>
#include <iostream>

using namespace std;

// 题目要求用分治法，没试过，下次得试试

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	if(nums.empty()) return 0;

        int s = 0; // sum
        int max_sum = nums[0];
        for(int i: nums)
        {
        	s += i;
        	max_sum = std::max(s, max_sum);
        	if(s < 0)
        		s = 0;
        }

        return max_sum;
    }
};
static int fast = [](){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	int ret = s.maxSubArray(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



