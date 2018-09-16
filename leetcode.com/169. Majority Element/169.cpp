/*
 * 169.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */

#include <iostream>
#include <unordered_map>
#include <vector>

// 没要求时间和空间复杂度，随便做了

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	std::unordered_map<int, int> times;
    	int max_times = 0;
        for(int i: nums)
        {
        	auto it = times.find(i);
        	if(it == times.end())
        	{
        		times.insert({i, 1});
        		max_times = std::max(max_times, 1);
        	}
        	else
        	{
        		++it->second;
        		max_times = std::max(it->second, max_times);
        	}
        }

        for(auto it = times.begin(); it != times.end(); ++it)
        {
        	if(it->second >= max_times)
        		return it->first;
        }
        return -1;
    }
};
