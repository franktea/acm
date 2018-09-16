/*
 * 11.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力，已经考虑到一定的条件跳过了，但结果还是很慢

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int result = 0;
        for(int i = 0; i < height.size(); ++i)
        {
        		for(int j = height.size() - 1; j > i; --j)
        		{
        			if(height[i] * (j-i) < result)
        				break;

        			const int area = (j-i) * std::min(height[i], height[j]);
        			result = std::max(result, area);
        		}
        }

        return result;
    }
};

int main()
{
	Solution* ps = new Solution;
	std::vector<int> v = {1,8,6,2,5,4,8,3,7};
	int ret = ps->maxArea(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}


