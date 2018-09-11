/*
 * 75.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: frank
 */
#include <algorithm>
#include <vector>
#include <iostream>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../3rdparty/unit_test/catch2/catch.hpp"

using namespace std;

// 将某个值的元素全部移到后面去，先移2、再移1。

class Solution {
public:
    void sortColors(vector<int>& nums) {
    	if(nums.empty()) return;
    	// 先把2全部移到后面去
    	auto it = Arrange(nums, nums.begin(), nums.end(), 2);
		for(int i: nums)
			cout<<i<<", ";
		cout<<"\n";

    	// 再把1全部移到后面去
    	Arrange(nums, nums.begin(), it, 1);
		for(int i: nums)
			cout<<i<<", ";
		cout<<"\n";
    	// 剩下的肯定就是0了
    }
public:
    // 把值等于value的元素全部移到最后去
    vector<int>::iterator Arrange(vector<int>& nums, vector<int>::iterator first, vector<int>::iterator last, int value)
    {
    	vector<int>::iterator first_of_value = std::find(first, last, value);
    	auto f = [value](int v)->bool{return v != value;};
    	vector<int>::iterator first_not_of_value = std::find_if(first_of_value, last, f);
    	while(first_of_value != last && first_not_of_value != last)
    	{
    		std::swap(*first_of_value, *first_not_of_value);
    		++first_of_value;
    		++first_not_of_value;
    		first_of_value = std::find(first_of_value, last, value);
    		first_not_of_value = std::find_if(first_not_of_value, last, f);
    	}
    	return first_of_value;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

TEST_CASE("TEST ARRANGE")
{
	Solution* ps = new Solution;
	{
		vector<int> v = {0, 2, 1, 2, 2, 1, 2, 0, 0, 2, 1, 0, 0, 1, 1, 2};
//		vector<int>::iterator it = ps->Arrange(v, v.begin(), v.end(), 0);
//		REQUIRE(it == v.end() - 5);

		ps->sortColors(v);
//		for(int i: v)
//			cout<<i<<", ";
//		cout<<"\n";
	}
}
