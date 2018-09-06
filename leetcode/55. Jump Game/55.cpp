/*
 * 55.cpp
 *  55. Jump Game
 *  Created on: Sep 6, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>

using namespace std;

// 一次过了，但是性能一般？感觉已经是不错的方法了

class Solution {
public:
    bool canJump(vector<int>& nums) {
    	if(nums.empty()) return true;

    	vector<bool> reachable(nums.size(), false); // 数组，第i个元素的值表示从i处是否能到达末尾
    	reachable[nums.size()-1] = true;

    	for(int i = int(nums.size()) - 1; i >= 0; --i)
    	{
    		int v = nums[i];
    		if(i + v + 1 >= nums.size())
    		{
    			reachable[i] = true;
    			continue;
    		}

    		for(int j = 1; j <= v; ++j)
    		{
    			if(reachable[i+j])
    			{
    				reachable[i] = true;
    				break;
    			}
    		}
    	}

    	return reachable[0];
    }
};

static int fast = [](){std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<int> v = {3,2,1,0,4};
	Solution* ps = new Solution;
	bool ret = ps->canJump(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



