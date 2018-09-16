/*
 * 119.cpp
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
    vector<int> getRow(int rowIndex) {
        vector<int> arr1(33, 1);
        vector<int> arr2(33, 1);

        for(int i = 0; i <= rowIndex; ++i)
        {
        	for(int j = 0; j <= i; ++j)
        	{
        		if(j == 0 || j == i)
        			arr2[j] = 1;
        		else
        			arr2[j] = arr1[j-1] + arr1[j];
        	}
        	arr1.assign(arr2.begin(), arr2.begin() + i + 1);
        }

        arr1.resize(rowIndex+1);
        return arr1;
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();


int main()
{
	Solution s;
	auto&& v = s.getRow(8);
	for(int i: v)
		cout<<i<<", ";
	cout<<"\n";
	return 0;
}

