/*
 * 200.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */
#include <vector>
#include <iostream>

using namespace std;

// 没啥好说的不用测试只要编过就通过，使用二维数组的时候注意y和x别弄反了

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	if(grid.empty()) return 0;

    	const int height = grid.size();
        const int width = grid[0].size();

        bool* arr = new bool[height*width];
        memset(arr, 0, sizeof(bool)*height*width);

        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {-1, 0, 1, 0};

        int result = 0;
        for(int x = 0; x < width; ++x)
        {
        	for(int y = 0; y < height; ++y)
        	{
        		if(grid[y][x] == '1' && !arr[y*width+x])
        		{
        			++result;
        			dfs(grid, arr, height, width, dx, dy, x, y);
        		}
        	}
        }
        return result;
    }
private:
    void dfs(vector<vector<char>>& grid, bool*& arr, int height, int width, const int* dx, const int* dy, int x, int y)
	{
    	arr[y*width+x] = true;
    	for(int i = 0; i < 4; ++i)
    	{
    		const int x2 = x + dx[i];
    		const int y2 = y + dy[i];
    		if(x2 >= 0 && x2 < width && y2 >= 0 && y2 < height && !arr[y2*width+x2] && grid[y2][x2] == '1')
    		{
    			dfs(grid, arr, height, width, dx, dy, x2, y2);
    		}
    	}
    };
};

int main()
{
	return 0;
}



