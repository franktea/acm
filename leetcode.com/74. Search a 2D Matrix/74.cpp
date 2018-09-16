/*
 * 74.cpp
 *
 *  Created on: Sep 9, 2018
 *      Author: frank
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 将二维数组映射成一维数组，来进行二分查找


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.empty()) return false;
    	const int width = matrix[0].size();
    	const int height = matrix.size();
    	const int length = width * height;

    	int low = 0;
    	int high = length - 1;

    	auto f = [&matrix, width, height](int index)->int {
    		int y = index / width;
    		int x = index % width;
    		return matrix[y][x];
    	};

    	while(low <= high)
    	{
    		int mid = (low + high) / 2;
    		const int value = f(mid);
    		if(value == target)
    			return true;

    		if(value < target)
    			low = mid + 1;
    		else
    			high = mid - 1;
    	}

    	return false;
    }
};
static int fast = [](){ios::sync_with_stdio(1);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<vector<int>> v = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
	Solution s;
	bool ret = s.searchMatrix(v, 3);
	cout<<"ret="<<ret<<"\n";
	return 0;
}
