/*
 * 33.cpp
 *  33. Search in Rotated Sorted Array
 *  Created on: Sep 8, 2018
 *      Author: frank
 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// 既然是要O(LogN)的复杂度，肯定是二分查找。先用二分查找找到数组中最小的元素的位置，
// 从这个位置，数组被分成了2个排序的区间，在这二个排序的区间中可以用二分查找来找到目标元素
// 此解法打败了98%的对手

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if(nums.empty())
    		return -1;

    	if(nums.size() == 1)
    		return nums[0] == target ? 0 : -1;

    	if(nums[0] < nums[nums.size() - 1]) // 此时为一个完整的排序序列，即未经过任何rotate
    	{
    		auto it = std::lower_bound(nums.begin(), nums.end(), target);
    		if(it == nums.end())
    			return -1;

    		if(*it != target)
    			return -1;

    		return std::distance(nums.begin(), it);
    	}
    	else
    	{
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

			//cout<<"min_index="<<min_index<<"\n";

			// 现在已经找到了分界点，[0, min_index)是一个升序排列的序列，[min_index, nums.end)也是一个升序的序列。
			// 只要在这2个区间中找即可。
			auto mid_it = nums.begin() + min_index;

			if(target >= nums[0])
			{
				auto it = std::lower_bound(nums.begin(), mid_it, target);
				return it == mid_it ? -1 : (*it == target ? std::distance(nums.begin(), it) : -1);
			}
			else
			{
				auto it = std::lower_bound(mid_it, nums.end(), target);
				return it == nums.end() ? -1 : (*it == target ? std::distance(nums.begin(), it): -1);
			}
    	}
    }
};

static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<int> v = //{4,5,6,7,0,1,2};
			{5,1,3};
			//{4, 5, 1, 2, 3};
	Solution* ps = new Solution;
	int index = ps->search(v, 3);
	cout<<"result="<<index<<"\n";
	return 0;
}


