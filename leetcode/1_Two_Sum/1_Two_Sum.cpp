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

        std::sort(sorted.begin(), sorted.end(), f);

        for(auto it = sorted.begin(); it != sorted.end(); ++it)
        {
        	int v = target - *it->second;
        	auto it2 = std::lower_bound(it, sorted.end(), v, f);
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
