/*
 * 1_Two_Sum.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: frank
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 先排序再查找的方法，没那么简单，要考虑到有重复元素的情况，得使用stable_sort

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<std::pair<int, int>> sorted;
    	sorted.reserve(nums.size());
    	for(int i = 0; i < int(nums.size()); ++i)
    	{
    		sorted.push_back({i, nums[i]});
    	}
    	auto f = [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) { return p1.second < p2.second; };

        std::stable_sort(sorted.begin(), sorted.end(), f);

        for(auto it = sorted.begin(); it != sorted.end(); ++it)
        {
        	int v = target - it->second;

        	// lower_bound的第三个参数必须与*it类型相同，由于此处first不重要，只比较second，所以构造一个临时的即可
        	auto it2 = std::lower_bound(it + 1, sorted.end(), std::pair<int, int>(0, v), f);
        	if(it2 != sorted.end() && it2->second == v)
        	{
        		int a = it->first;
        		int b = it2->first;
        		if(a > b)
        			std::swap(a, b);
        		return {a, b};
        	}
        }

        return {};
    }
};

int main()
{
	vector<int> v = {3, 2, 4};
	Solution* ps = new Solution;
	vector<int> r = ps->twoSum(v, 6);
	for(auto i: r)
		cout<<i<<" ";
	cout<<"\n";
	return 0;
}
