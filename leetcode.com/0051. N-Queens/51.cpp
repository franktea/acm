/*
 * 51.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: frank
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 用递归的方法，一次性通过。

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    	if(n <= 0) return result_;

    	arr_.resize(n);
    	NQueens(0);
    	return result_;
    }
private:
    void NQueens(int level)
    {
    	if(level == arr_.size())
    	{
    		OutPut();
    		return;
    	}

    	for(int i = 0; i < arr_.size(); ++i)
    	{
    		arr_[level] = i;
    		if(! Check(level))
    			continue;

    		NQueens(level + 1);
    	}
    }

    void OutPut()
    {
    	vector<string> vs;
    	for(int i = 0; i < arr_.size(); ++i)
    	{
    		string str(arr_.size(), '0');
    		for(int j = 0; j < arr_.size(); ++j)
    		{
    			str[j] = arr_[i] == j ? 'Q' : '.';
    		}
    		vs.push_back(str);
    	}
    	result_.push_back(vs);
    }

    bool Check(int level) // 只用检测竖向和斜向，而且只用对每次新添加的最后一个进行检查，因为前面的肯定都是检查好的
    {
    	// 检查竖向
    	const int col = arr_[level]; // 最后一个
    	for(int i = 0; i < level; ++i)
    	{
    		if(arr_[i] == col)
    			return false;
    	}

    	// 检查斜向
    	for(int i = 0; i < level; ++i)
    	{
    		const int dx = col > arr_[i] ? col - arr_[i] : arr_[i] - col;
    		if(dx == level - i)
    			return false;
    	}

    	return true;
    }
private:
	vector<vector<string>> result_;
    vector<int> arr_; // 用一个一维数组来记录递归选择的结果，arr_[i]表示在第i层第arr_[i]个元素摆放了queen
};

static int fast = [](){std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	vector<vector<string>> ret = ps->solveNQueens(4);
	for(const vector<string>& vs: ret)
	{
		cout<<"[\n";
		for(const string& str: vs)
			cout<<str<<"\n";
		cout<<"]\n";
	}
	return 0;
}



