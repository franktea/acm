/*
 * 120.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	if(triangle.empty()) return 0;

    	for(int index = triangle.size() - 2; index >= 0; --index)
    	{
    		for(int x = 0; x <= index; ++x)
    		{
    			triangle[index][x] += std::min(triangle[index+1][x], triangle[index+1][x+1]);
    		}
    	}

    	return triangle[0][0];
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	vector<vector<int>> v = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	int ret = ps->minimumTotal(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



