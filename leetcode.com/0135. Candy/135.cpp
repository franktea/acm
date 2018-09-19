/*
 * 135.cpp
 *
 *  Created on: Sep 19, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 一次通过，打败98%。
// 方法如下：首先遍历一次，把”谷底“找出来，将这些值都设置为1；
// 其次，通过这些“谷底”，一次向左、向右扫描，像爬山一样，遇到更大的就加1. 如果有某个值被设置两次，就取两次里面最大的那个。
// 比如说1 2 3 4 5 1，如果从左边的1去扫描，5处应该设置为5，而从右边的1去扫，只需要设置为2。所以需要取最大值5

class Solution {
public:
    int candy(vector<int>& ratings) {
    	if(ratings.empty()) return 0;

    	vector<int> counts; // 每个位置的糖果数量
    	counts.resize(ratings.size(), 0);

    	// 判断是否应该设置为1
    	auto valley = [&ratings](int index){
    		if(ratings.size() == 1) return true;

    		if(index == 0) return ratings[index+1] >= ratings[index];
    		if(index == ratings.size()-1) return ratings[index-1] >= ratings[index];
    		return ratings[index+1] >= ratings[index] && ratings[index-1] >= ratings[index];
    	};

    	// 将所有谷底的值设置为1
    	for(int index = 0; index < ratings.size(); ++index)
    	{
    		if(valley(index))
    			counts[index] = 1;
    	}

    	auto climb = [&ratings, &counts](int index){
    		//left
    		for(int i = index - 1; i >= 0 && ratings[i] > ratings[i+1]; --i)
    		{
    			if(counts[i] >= counts[i+1]+1)
    				break;
    			counts[i] = counts[i+1]+1;
    		}
    		//right
    		for(int i = index + 1; i < ratings.size() && ratings[i] > ratings[i-1]; ++i)
    		{
    			if(counts[i] > counts[i-1]+1)
    				break;
    			counts[i] = counts[i-1]+1;
    		}
    	};

    	// 从最低点向左右扫描，设置所有的值
    	for(int index = 0; index < ratings.size(); ++index)
    	{
    		if(valley(index))
    			climb(index);
    	}

//    	for(int c: counts)
//    		cout<<c<<",";
//    	cout<<"\n";

    	return std::accumulate(counts.begin(), counts.end(), 0);
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	vector<int> v = {1,2,2,2,3,3,4,3};
	int ret = ps->candy(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



