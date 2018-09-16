/*
 * 62.cpp
 *
 *  Created on: Sep 8, 2018
 *      Author: frank
 */
#include <iostream>

using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        static const int N = 101;
        int arr[N][N] = {0};

        arr[n-1][m-1] = 1;
        for(int x = m - 1; x >= 0; --x)
        {
        		for(int y = n - 1; y >= 0; --y)
        		{
        			if(x + 1 <= m - 1)
        				arr[y][x] += arr[y][x+1];
        			if(y + 1 <= n - 1)
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
	Solution* ps = new Solution;
	int ret = ps->uniquePaths(7, 3);
	cout<<"ret="<<ret<<"\n";
	return 0;
}

