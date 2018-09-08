/*
 * 54.cpp
 *  54. Spiral Matrix
 *  Created on: Sep 8, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 其实是有规律可循的，方向是右下左上循环、每次的步进也是width-n、height-n
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;

        result.assign(matrix[0].begin(), matrix[0].end()); // 第一行直接放进去

        const int width = matrix[0].size();
        const int height = matrix.size();

        int delta = 0;
        // 现在前进的初始位置在第一排最后一个
        int x = width - 1;
        int y = 0;
        while(1)
        {
    		// 依次朝下、左、上、右循环
        		// 先向下走height - delta, 再向左走width - delta
        		int down = height - delta -1;
        		if(down <= 0)
        			break;
        		for(int dy = 1; dy <= down; ++dy)
        		{
        			++y;
        			//cout<<"down:"<<matrix[y][x]<<"\n";
        			result.push_back(matrix[y][x]);
        		}

        		int left = width - delta - 1;
        		if(left <= 0)
        			break;
        		for(int dx = 1; dx <= left; ++dx)
        		{
        			--x;
        			//cout<<"left:"<<matrix[y][x]<<"\n";
        			result.push_back(matrix[y][x]);
        		}

        		++ delta;
        		// 再向上走height - delta， 再向右走width - delta
        		int up = height - delta - 1;
        		if(up <= 0)
        			break;
        		for(int dy = 1; dy <= up; ++dy)
        		{
        			--y;
        			//cout<<"up:"<<matrix[y][x]<<"\n";
        			result.push_back(matrix[y][x]);
        		}

        		int right = width - delta - 1;
        		if(right <= 0)
        			break;
        		for(int dx = 1; dx <= right; ++dx)
        		{
        			++x;
        			//cout<<"right:"<<matrix[y][x]<<"\n";
        			result.push_back(matrix[y][x]);
        		}

        		++delta;
        }
        return result;
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
	//{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	Solution* ps = new Solution;
	const auto& v = ps->spiralOrder(matrix);
	for(int i: v)
	{
		cout<<i<<", ";
	}
	cout<<"\n";
	return 0;
}
