/*
 * 121.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if(prices.empty()) return result;

        for(int i = 0; i < prices.size(); ++i)
        {
        	for(int j = i + 1; j < prices.size(); ++j)
        	{
        		result = std::max(prices[j] - prices[i], result);
        	}
        }

        return result;
    }
};

int main()
{
	return 0;
}



