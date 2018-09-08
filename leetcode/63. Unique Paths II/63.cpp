/*
 * 63.cpp
 *  63. Unique Paths II
 *  Created on: Sep 8, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
using namespace std;

// 和62有点像

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	if(obstacleGrid.empty()) return 0;

        static const int N = 101;
        int arr[N][N] = {0};

        const int m = obstacleGrid[0].size(); // width
        const int n = obstacleGrid.size(); // height

        arr[n-1][m-1] = obstacleGrid[n-1][m-1] ? 0 : 1;
        for(int x = m - 1; x >= 0; --x)
        {
        		for(int y = n - 1; y >= 0; --y)
        		{
        			if(obstacleGrid[y][x])
        			{
        				arr[y][x] = 0;
        				continue;
        			}

        			if(x + 1 <= m - 1 && obstacleGrid[y][x+1] != 1)
        				arr[y][x] += arr[y][x+1];
        			if(y + 1 <= n - 1 && obstacleGrid[y+1][x] != 1)
        				arr[y][x] += arr[y+1][x];
        			//cout<<"("<<x<<","<<y<<")="<<arr[y][x]<<"\n";
        		}
        }

        return arr[0][0];
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();


int main()
{
	vector<vector<int>> g = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
	Solution* ps = new Solution;
	int ret = ps->uniquePathsWithObstacles(g);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



