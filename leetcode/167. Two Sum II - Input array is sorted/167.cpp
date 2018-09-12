/*
 * 167.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 这么简单居然几次才过，注意一些边界问题

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        if(numbers.empty())
        	return result;

        for(auto it = numbers.begin(); it != numbers.end(); ++it)
        {
        	if(*it > target)
        		return result;

        	int v = target - *it;
        	auto i = std::lower_bound(it + 1, numbers.end(), v);
        	if(i == numbers.end() || *i != v)
        		continue;

        	result.push_back(std::distance(numbers.begin(), it) + 1);
        	result.push_back(std::distance(numbers.begin(), i) + 1);
        	return result;
        }

        return result;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
