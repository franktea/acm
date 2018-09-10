/*
 * 80.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 思路：循环，每次拷贝一个字符，如果碰到有相同的，则拷贝二个。
// O(N)的复杂度，但是性能不是很高。
// 只保证了前n个字符是需要的样子，并没有把不需要的相对移动到后面去

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int result = 0;
        int index = 0;
        while(index < nums.size())
        {
        	nums[result++] = nums[index]; // 拷贝一个字符

        	int second = index + 1;
        	if(second >= nums.size())
        		break;

        	if(nums[index] == nums[second])
        	{
        		nums[result++] = nums[second];
        		while(second < nums.size() && nums[second] == nums[index])
        			++ second;
        	}

        	index = second;
        }

//        for(auto&& i: nums)
//        	cout<<i<<", ";
//        cout<<"\n";

        return result;
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	vector<int> v = {1,1,1,1,2,2,3};
	int ret = ps->removeDuplicates(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



