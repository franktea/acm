/*
 * 59.cpp
 *  59. Spiral Matrix II
 *  Created on: Sep 8, 2018
 *      Author: frank
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        if(n <= 0) return result;

        // 先生成第一行
        result.resize(n);
        for(int i = 1; i <= n; ++i)
        {
        		result[0].push_back(i);
        }

        for(int i = 1; i < n; ++i)
        		result[i].resize(n);

        int current = n;
        int delta = 0;
        // 现在前进的初始位置在第一排最后一个
        int x = n - 1;
        int y = 0;
        while(1)
        {
    		// 依次朝下、左、上、右循环
        		// 先向下走height - delta, 再向左走width - delta
        		int down = n - delta -1;
        		if(down <= 0)
        			break;
        		for(int dy = 1; dy <= down; ++dy)
        		{
        			++y;
        			//cout<<"down:"<<matrix[y][x]<<"\n";
        			result[y][x] = ++current;
        		}

        		int left = n - delta - 1;
        		if(left <= 0)
        			break;
        		for(int dx = 1; dx <= left; ++dx)
        		{
        			--x;
        			//cout<<"left:"<<matrix[y][x]<<"\n";
        			result[y][x] = ++ current;
        		}

        		++ delta;
        		// 再向上走height - delta， 再向右走width - delta
        		int up = n - delta - 1;
        		if(up <= 0)
        			break;
        		for(int dy = 1; dy <= up; ++dy)
        		{
        			--y;
        			//cout<<"up:"<<matrix[y][x]<<"\n";
        			result[y][x] = ++ current;
        		}

        		int right = n - delta - 1;
        		if(right <= 0)
        			break;
        		for(int dx = 1; dx <= right; ++dx)
        		{
        			++x;
        			//cout<<"right:"<<matrix[y][x]<<"\n";
        			result[y][x] = ++ current;
        		}

        		++delta;
        }
        return result;
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();


int main()
{
	Solution* ps = new Solution;
	vector<vector<int>> result = ps->generateMatrix(5);
	for(const vector<int>& v: result)
	{
		for(int i: v)
			cout<<i<<", ";
		cout<<"\n";
	}
	return 0;
}


