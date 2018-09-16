/*
 * 171.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 和168一样

class Solution {
public:
	int titleToNumber(string s) {
    	int result = 0;
    	int times = 1;
    	for(auto it = s.rbegin(); it != s.rend(); ++it)
    	{
    		char c = *it;
    		int v = c - 'A' + 1;
    		result += v*times;
    		times *= 26;
    	}
    	return result;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	int ret = ps->titleToNumber("ZY");
	cout<<"ret="<<ret<<"\n";
	return 0;
}


