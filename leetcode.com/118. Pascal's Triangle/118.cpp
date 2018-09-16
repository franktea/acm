/*
 * 118.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.resize(numRows);
        for(int index = 0; index < numRows; ++index)
        	result[index].resize(index+1);

        for(int i = 0; i < result.size(); ++i)
        	for(int j = 0; j <= i; ++j)
        	{
        		if(j == 0 || j == i)
        			result[i][j] = 1;
        		else
        			result[i][j] = result[i-1][j-1] + result[i-1][j];
        	}

        return result;
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution s;
	auto&& vv = s.generate(8);
	for(auto&& v: vv)
	{
		for(int i: v)
			std::cout<<i<<", ";
		std::cout<<"\n";
	}

	return 0;
}



