/*
 * 154.cpp
 *  154. Find Minimum in Rotated Sorted Array II
 *  Created on: Sep 8, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 和153相比，有重复的似乎没那么简单了，先排序然后通过了再说

class Solution {
public:
    int findMin(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
        return nums[0];
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<int> v = {1,1};
	Solution* ps = new Solution;
	int ret = ps->findMin(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



