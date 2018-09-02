/*
 * 13.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: frank
 */
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	// 从右到左遍历
    	if(s.empty()) return 0;

    	//std::map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    	// 用数组代替map，速度非常之快了
    	int values[26] = {0};
    	values['I'-'A'] = 1;
    	values['V'-'A'] = 5;
    	values['X'-'A'] = 10;
    	values['L'-'A'] = 50;
    	values['C'-'A'] = 100;
    	values['D'-'A'] = 500;
    	values['M'-'A'] = 1000;

    	int result = 0;
    	int last_max = 0; // 左减右加，碰到没个字符都要判断是加还是减，记录扫描到的最大数字，如果碰到更小的，就是减法
    	for(int i = s.size() - 1; i >= 0; --i)
    	{
    		const char c = s[i];
			int v = values[c-'A'];
			if(v < last_max)
				result -= v;
			else
				result += v;

			if(v > last_max)
				last_max = v;
    	}

    	return result;
    }
};

// 从优秀答案中看到，加上这句以后变得飞快
static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

int main()
{
	Solution s;
	int ret = s.romanToInt("IV");
	cout<<"ret="<<ret<<"\n";
	return 0;
}

