/*
 * 81.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


// 有重复元素的，暂时想不到O(logN)的方法，先排序再查找
// 这种方法打败了98%+的人，看来大家都是用的这种方法

class Solution {
public:
    bool search(vector<int>& nums, int target) {
    	std::sort(nums.begin(), nums.end());
    	return std::binary_search(nums.begin(), nums.end(), target);
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	return 0;
}



