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

// 感觉上确实有很多重复计算的地方，但是暂时不知道怎么用dp，用遍历的方法，打败了65%。
// 以每个点为左上角(x, y)，扫描所有可能的右下角形成的最大为1的矩形。
// 有一个技巧，在当前左上角的所有右下角中，只要碰到任何一个不为1的点，后面就不用再扫了，因为要找的是全部为1的矩形。

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



