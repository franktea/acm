/*
 * 42.cpp
 *
 *  Created on: Sep 13, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 从前到后遍历到最高的地方，然后再从后向前遍历到最高的地方，
// 复杂度O(N*N)，但是也打败了100%

class Solution {
public:
    int trap(vector<int>& height) {
    	if(height.empty()) return 0;

    	// 两端为0的都去掉
    	int index = 0;
    	while(index < height.size() && height[index] == 0)
    		++index;
    	height.erase(height.begin(), height.begin() + index);

    	if(height.empty()) return 0;

    	index = height.size() - 1;
    	while(index >= 0 && height[index] == 0)
    		--index;
    	height.erase(height.begin() + index + 1, height.end());

    	if(height.empty()) return 0;

//    	for(int i: height)
//    		cout<<i<<", ";
//    	cout<<"\n";

    	int result = 0;

    	// 从前往后遍历，找到第一个大于等于当前元素的index，如果没找到，则从后往前遍历
    	index = 0;
    	while(index < height.size())
    	{
    		auto it = std::find_if(height.begin()+index+1, height.end(), [&height, index](int v){
    			return v >= height[index];
    		});

    		if(it == height.end())
    			break;

    		int index2 = std::distance(height.begin(), it);
    		for(int i = index+1; i < index2; ++i)
    		{
    			//cout<<"::::"<<"i="<<i<<", index="<<index<<"\n";
    			result += height[index] - height[i];
    		}

    		index = index2;
    	}

    	//cout<<"===>ret="<<result<<"\n";

    	// 从后往前找
    	if(index == height.size() - 1) return result;
    	int last_index = height.size() - 1;
    	while(last_index > index)
    	{
    		if(last_index - 1 > index && height[last_index-1] >= height[last_index])
    		{
    			--last_index;
    			continue;
    		}

    		int itmp = last_index - 1;
    		while(itmp > index && height[itmp] <= height[last_index])
    			--itmp;

    		for(int i = last_index; i > itmp; --i)
    		{
    			result += height[last_index] - height[i];
    		}

    		last_index = itmp;
    	}

    	return result;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	vector<int> v = {0,0,0,1,0,2,1,0,1,3,2,1,2,1,0,0,0};
	int ret = ps->trap(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



