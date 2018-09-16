/*
 * 84.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// O(N*N)的解法，效率果然很低。下次想想有无更简单的方法
// 针对每个元素，找到以这个元素为高的最大面积

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	if(heights.empty()) return 0;

    	int max_area = 0;

    	for(int i = 0; i < heights.size(); ++i)
    	{
    		if(heights[i] == 0)
    			continue;

    		if(i-1 > 0 && heights[i-1] == heights[i]) // 如果和上一个相等，则之前已经算过了，无需再算了
    			continue;

    		int low = i - 1;
    		while(low >= 0 && heights[low] >= heights[i]) // 向前搜索高于当前元素的所有元素
    			-- low;
    		++low;
    		int high = i + 1;
    		while(high < heights.size() && heights[high] >= heights[i]) // 向后搜索高于当前元素的所有元素
    			++ high;

    		const int area = heights[i] * (high - low);
    		max_area = std::max(area, max_area);
    	}

    	return max_area;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<int> h = {2,1,5,6,2,3};
	Solution* ps = new Solution;
	int ret = ps->largestRectangleArea(h);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



