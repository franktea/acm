/*
 * 174.cpp
 *
 *  Created on: Sep 8, 2018
 *      Author: frank
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()) return 1;

        vector<vector<int>> grid;
        grid.resize(dungeon.size());
        for(vector<int>& v: grid)
        		v.resize(dungeon[0].size(), 0);

        const int width = grid[0].size();
        const int height = grid.size();

        // 注意x和y不要搞反了！！！！
        for(int x = width - 1; x >= 0; --x)
        {
        		for(int y = height - 1; y >= 0; --y)
        		{
            		if(x+1 >= width && y+1 >= height)
            		{
            			grid[y][x] = dungeon[y][x] >= 0 ? 1 : 1 - dungeon[y][x];
            		}
            		else if(x+1 >= width)
            		{
            			grid[y][x] = dungeon[y][x] - grid[y+1][x] >= 0 ? 1 : - dungeon[y][x] + grid[y+1][x];
            		}
            		else if(y+1 >= height)
            		{
            			grid[y][x] = dungeon[y][x] - grid[y][x+1] >= 0 ? 1 : - dungeon[y][x] + grid[y][x+1];
            		}
            		else
            		{
            			grid[y][x] = std::min(dungeon[y][x] - grid[y][x+1] >= 0 ? 1 : - dungeon[y][x] + grid[y][x+1],
            					dungeon[y][x] - grid[y+1][x] >= 0 ? 1 : - dungeon[y][x] + grid[y+1][x]);
            		}
        		}
        }

//        for(const vector<int>& v: grid)
//        {
//        		for(int i: v)
//        			cout<<i<<", ";
//        		cout<<"\n";
//        }

        return grid[0][0];
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<vector<int>> v = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
		//{{0,0}};
	Solution* ps = new Solution;
	int ret = ps->calculateMinimumHP(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



