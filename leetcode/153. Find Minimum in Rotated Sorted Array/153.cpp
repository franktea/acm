/*
 * 153.cpp
 *  153. Find Minimum in Rotated Sorted Array
 *  Created on: Sep 8, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 和33有点像

class Solution {
public:
    int findMin(vector<int>& nums) {
    	if(nums.empty()) return 0;  //impossible
    	if(nums.size() == 1) return nums[0];

    	if(nums[0] < nums[nums.size()-1]) // 未经过任何rotate
    		return nums[0];

		int min_index = -1; // 数组中最小的元素的下标，即本来排在数组第一个位置的元素下标。
		int low = 0;
		int high = nums.size() - 1;
		while(low < high) // 标准二分搜索算法此处是<=，但是对于这种搜索不对
		{
			int mid = (low + high) / 2;
			if(nums[mid] > nums[mid+1]) // 第一个nums[n] > nums[n+1]的位置，就是数组的分界点
			{
				min_index = mid + 1;
				break;
			}

			if(nums[mid] > nums[0])
			{
				low = mid;  // 一般的二分出查找这个地方应该是 mid+1，但是这个地方用mid+1结果不对，具体没想过为什么
			}
			else
			{
				high = mid;
			}
		}
		return nums[min_index];
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<int> v = {4,5,6,7,0,1,2};
	Solution* ps = new Solution;
	int ret = ps->findMin(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}


