/*
 * 115_3.cpp
 *
 *  Created on: Sep 14, 2018
 *      Author: frank
 */
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 根据115_2.cpp的方法，采用填充数组的算法;
// 已经很简单了，但是并未打败100%

// 此题的优化空间：vector的构造，可以用二维数组；每行数据的计算，其实每行只需要计算2个数值，而不是全部算完，这样说来根本不需要表格

class Solution {
public:
    int numDistinct(string s, string t) {
    	const int height = s.length()+1;
    	const int width = t.length()+1;

    	vector<vector<int>> arr;
    	arr.resize(height);
    	for(vector<int>& v: arr)
    		v.resize(width, -1);

    	// 这两行的初始化很重要
    	for(int i = 0; i < width; ++i)
    		arr[height-1][i] = 0;
    	for(int i = 0; i < height; ++i)
    		arr[i][width-1] = 1;

    	for(int i = s.length()-1; i >= 0; --i)
    	{
    		for(int j = t.length()-1; j >= 0; --j) // 用递推公式
    		{
    			if(s[i] != t[j])
    				arr[i][j] = arr[i+1][j];
    			else
    				arr[i][j] = arr[i+1][j] + arr[i+1][j+1];
    		}
    	}

//    	for(const vector<int>& v: arr)
//    	{
//    		for(int i: v)
//    			cout<<i<<", ";
//    		cout<<"\n";
//    	}

    	return arr[0][0];
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	int ret = ps->numDistinct("babgbag", "bag");
	cout<<"ret="<<ret<<"\n";
	return 0;
}



