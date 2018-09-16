/*
 * 22.cpp
 *
 *  Created on: Sep 9, 2018
 *      Author: frank
 */
#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 想到一个不是很好的方法，会生成重复的解，需要去重：
// f1: ()
// f2: (()), ()()
// f3: ((()), (()()), ()(()), ()()(), (())(), ()()()...
// 即fn是在f(n-1)的每个解法两边加括号、以及放在每个解的左边、右边。然后再去重、排序

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> result;
    	if(n == 0) return result;
    	if(n == 1) return vector<string>{"()"};

    	result = {"()"};
    	unordered_set<string> tmp1;
    	for(int i = 2; i <= n; ++i)
    	{
    		for(const string& str: result)
    		{
    			tmp1.insert(string("(")+str+string(")"));
    			tmp1.insert(string("()")+str);
    			tmp1.insert(str+string("()"));
    		}
    		result.clear();
    		result.assign(tmp1.begin(), tmp1.end());
    		tmp1.clear();
    	}
    	std::sort(result.begin(), result.end());
    	return result;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution s;
	vector<string> v = s.generateParenthesis(3);
	for(auto&& str: v)
	{
		cout<<str<<"\n";
	}
	return 0;
}



