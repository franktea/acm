/*
 * 70.cpp
 *
 *  Created on: Sep 9, 2018
 *      Author: frank
 */
#include <iostream>

using namespace std;

// f(n)与f(n-1)的关系，在所有f(n-1)之前走一步，或者在所有f(n-2)前走2步，于是：
// f(n) = f(n-1) + f(n-2)
// 1 2 3 5 8 13

class Solution {
public:
    int climbStairs(int n) {
    	if(n <= 1) return 1;
    	if(n == 2) return 2;

    	int x1 = 1;
    	int x2 = 2;
    	for(int i = 3; i <= n; ++i)
    	{
    		int x = x1 + x2;
    		x1 = x2;
    		x2 = x;
    	}

    	return x2;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution s;
	int ret = s.climbStairs(5);
	cout<<"ret="<<ret<<"\n";
	return 0;
}

