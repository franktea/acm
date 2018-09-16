/*
 * 64.cpp
 *  64. Minimum Path Sum
 *  Created on: Sep 6, 2018
 *      Author: frank
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if(grid.empty()) return 0;

        const int height = grid.size();
        const int width = grid[0].size();

        for(int w = width - 1; w >= 0; --w)
        	for(int h = height - 1; h >= 0; --h)
        	{
        		if(w + 1 >= width && h + 1 >= height)
        			continue;

        		if(w + 1 >= width)
        			grid[h][w] += grid[h+1][w];
        		else if(h + 1 >= height)
        			grid[h][w] += grid[h][w+1];
        		else
        			grid[h][w] += std::min(grid[h][w+1], grid[h+1][w]);
        	}

        return grid[0][0];
    }
};

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

int main()
{

}


