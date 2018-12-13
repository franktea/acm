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

// n个括号生成的字符串共有2n个元素，每个元素有2种可能：左括号、右括号。
// 用递归即可，深度优先，复杂度2**2n

class Solution {
public:
    vector<string> generateParenthesis(int n)
	{
    	vector<string> ret;
    	string tmp;
    	tmp.resize(2*n);
    	dfs(ret, tmp, 0, 0, 2*n);
    	return ret;
    }
private:
    // sum 表示当前生成的字符串的值的和，左括号为1，右括号为-1，路径上所有的和都必须大于等于0，如果小于0，则肯定不是合法字符串。
    void dfs(vector<string>& result, string& str, const int sum, const int depth, const int max_depth)
    {
    	if(depth >= max_depth)
    	{
    		if(sum == 0)
    			result.push_back(str);
    		return;
    	}

    	const string s = "()";
    	for(const char c: s)
    	{
    		const int v = sum + value(c);
    		if(v < 0)
    			continue;

    		str[depth] = c;
    		dfs(result, str, v, depth+1, max_depth);
    	}
    }

    int value(char c)
    {
    	return c == '(' ? 1 : -1;
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



