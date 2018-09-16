/*
 * 16.cpp
 * 16. 3Sum Closest
 *  Created on: Sep 3, 2018
 *      Author: frank
 */
#include <vector>
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// 用了最慢的方法，没有任何优化

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

    	std::sort(nums.begin(), nums.end());
    	int current_diff = std::numeric_limits<int>::max();
    	int result = 0;

    	for(size_t i = 0; i < nums.size(); ++i)
    		for(size_t j = i + 1; j < nums.size(); ++j)
    			for(size_t k = j + 1; k < nums.size(); ++k)
    			{
    				const int sum = nums[i] + nums[j] + nums[k];
    				const int diff = sum - target;
    				const int positive_diff = std::abs(diff);
    				if(positive_diff < current_diff)
    				{
    					result = sum;
    					current_diff = positive_diff;
    				}
    			}

    	return result;
    }
};

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

int main()
{
	Solution s;
	vector<int> v = {-1, 2, 1, -4};
	int ret = s.threeSumClosest(v, 1);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



