/*
 * 123.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 对于只卖一次，121已经有O(N)的方法了。
// 此题最多买两次，也就是说买1~2次，将数据分成两组，用N中分法，
// 每组求最大值时用121的O(N)的方法，最后比较得到结果，复杂度为O(N*N)
// 既然是O(N^2)的算法，效率肯定也不高，打败4%

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.empty()) return 0;

    	int result = MaxOf(prices, 0, prices.size()-1);
    	int result2 = 0;
    	for(int i = 1; i < prices.size(); ++i)
    	{
    		int ret = MaxOf(prices, 0, i-1) +
    				MaxOf(prices, i, prices.size()-1);
    		result2 = std::max(result2, ret);
    	}
    	return std::max(result, result2);
    }
private:
    int MaxOf(vector<int>& prices, int i, int j) // 求区间[i,j], i<=j，求此区间只买卖一次的最大收益。
    {
        	if(prices.empty()) return 0;

        	int result = 0;

            int min_value = prices[i];

            for(int x = i+1; x <= j; ++x)
            {
            	int v = prices[x];
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
	vector<int> v = {3,3,5,0,0,3,1,4};
	int ret = ps->maxProfit(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}
