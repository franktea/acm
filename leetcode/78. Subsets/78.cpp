/*
 * 78.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 计算一个集合的所有子集，可以用每个元素选和不选两种状态的方法来求解，共有2^n种结果，用递归的方法可以得出。
// 此解用循环，假设全集是1， 2， 3， 4，步骤如下：
// 最开始是空集 []
// 对于元素1，可以在空集的基础上，选和不选。如果不选，则和之前一样，即[]，如果选，则得到了[1]，于是1的结果为[], [1]
// 对于元素2，可以在之前1的结果上，选2和不选2.如果不选2，则和1的结果一样，即为[][1]；如果选2，则得到[2],[12]，于是2的结果为[][1][2][12]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> result;
    	vector<int> empty;
		result.push_back(empty);
    	if(nums.empty())
    	{
    		return result;
    	}

    	for(int i = 0; i < nums.size(); ++i)
    	{
    		vector<vector<int>> new_ones;
    		for(const vector<int>& v: result)
    		{
    			vector<int> tmp = v;
    			tmp.push_back(nums[i]);
    			new_ones.push_back(tmp);
    		}
    		result.insert(result.end(), new_ones.begin(), new_ones.end());
    	}

    	return result;
    }
};
static int fast = [](){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();


