/*
 * 14.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: frank
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 非常简单的题，但是展示了c++11里面利用lambda函数跳出嵌套循环的方法

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string result = "";
    	if(strs.empty()) return result;

    	[&]{ // 为了跳出跳套循环
    	for(size_t i = 0; ; ++i)
    	{
    		if(strs[0].size() < i)
    			break;

    		const char c = strs[0][i];
    		for(size_t j = 1; j < strs.size(); ++j)
    		{
    			if(strs[j].size() < i || strs[j][i] != c)
    				return;
    		}
    		result.push_back(c);
    	}
    	}();

    	return result;
    }
};

// 从优秀答案中看到，加上这句以后变得飞快
static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

int main()
{
	Solution s;
	vector<string> v = {"dog","racecar","car"};
	string ret = s.longestCommonPrefix(v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



