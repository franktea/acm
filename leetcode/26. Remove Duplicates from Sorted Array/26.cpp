/*
 * 26.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: frank
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//对于std::unique的实现需要仔细理解

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	auto it = std::unique(nums.begin(), nums.end());
    	return std::distance(nums.begin(), it);
    }
};

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();


int main()
{
	vector<int> v = {0,0,1,1,1,2,2,3,3,4};
	Solution* ps = new Solution;
	int len = ps->removeDuplicates(v);
	for(int i = 0; i < len; ++i)
		cout<<v[i]<<", ";
	cout<<"\n";

	return 0;
}



