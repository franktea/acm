/*
 * 121_2.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// O(N)的方法，从左到右扫描，记住之前最小的值，如果碰到比最小值大的，就计算看是否有更好的结果。
// 算是dp。加上fast打败100无压力。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.empty()) return 0;

    	int result = 0;

        int min_value = prices[0];

        for(int i = 1; i < prices.size(); ++i)
        {
        	int v = prices[i];
        	if(v < min_value)
        	{
        		min_value = v;
        	}
        	else if( v > min_value)
        	{
        		result = std::max(result, v - min_value);
        	}
        }

        return result;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	vector<int> v = {7,1,5,3,6,4};
	int ret = ps->maxProfit(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}


