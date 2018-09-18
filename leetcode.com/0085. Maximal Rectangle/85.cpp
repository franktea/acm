/*
 * 85.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <functional>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	if(matrix.empty()) return 0;

    	int ret = 0;

    	for(int y = 0; y < matrix.size(); ++y)
    	{
    		for(int x = 0; x < matrix[0].size(); ++x)
    		{
    			if(matrix[y][x] == '0')
    				continue;
    			ret = std::max(1, ret);

    			int max_x = matrix[0].size();
    			int max_y = matrix.size();

    			for(int dy = 0; y + dy < max_y; ++dy)
    			{
    				for(int dx = 0; x + dx < max_x; ++dx)
    				{
    					if(matrix[y+dy][x+dx] == '0')
    					{
    						max_x = x + dx;
    						break;
    					}

    					//cout<<"y="<<y<<", x="<<x<<", dy="<<dy<<", dx="<<dx<<", count: "<<(dx+1)*(dy+1)<<"\n";

    					int count_of_1 = (dx+1)*(dy+1);
    					ret = std::max(ret, count_of_1);
    				}
    				//cout<<"y="<<y<<", x="<<x<<", dy="<<dy<<"\n";
    			}
    		}
    	}

    	return ret;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	int ret;
	vector<vector<char>> matrix = {
			  {'1','0','1','0','0'},
			  {'1','0','1','1','1'},
			  {'1','1','1','1','1'},
			  {'1','0','0','1','0'}
			};
	ret = ps->maximalRectangle(matrix);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



