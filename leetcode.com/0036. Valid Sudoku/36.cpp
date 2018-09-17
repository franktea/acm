/*
 * 36.cpp
 *
 *  Created on: Sep 16, 2018
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
#include <sstream>
#include <array>
#include <random>

using namespace std;

// 题目意思不要弄错了！仅仅只是需要检查是否合格，根本不需要求出解，需要求出解的是下一题！
// 对于全部是空的情况，用遍历的方法求解是会超时的！所以下一题的case里面都是有可行解的，而本题中有全部是空格的case

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	for(vector<char>& v: board)
    		for(char& c: v)
    			c = c == '.' ? 0 : c - '0';

    	for(int i = 0; i < board.size(); ++i)
    	{
    		for(int j = 0; j < board[0].size(); ++j)
    		{
    			if(! Check(board, i, j))
    				return false;
    		}
    	}

    	return true;
    }
private:
    bool Check(vector<vector<char>>& board, int i, int j)
    {
    	//check row
    	{
    		const vector<char>& v = board[i];
    		int arr[10] = {0};
    		for(int c: v)
    		{
    			if(c && arr[c])
    				return false;

    			if(c)
    				arr[c] = 1;
    		}
    	}

    	//check col
    	{
    		int arr[10] = {0};
    		for(const vector<char>& v: board)
    		{
    			int c = v[j];
    			if(c && arr[c])
    				return false;

    			if(c)
    				arr[c] = 1;
    		}
    	}

    	//check sub matrix
    	{
    		int arr[10] = {0};
    		const int row = i / 3;
    		const int col = j / 3;
    		for(int x = 3*row; x < 3*row+3; ++x)
    		{
    			for(int y = 3*col; y < 3*col+3; ++y)
    			{
    				int c = board[x][y];
        			if(c && arr[c])
        				return false;

        			if(c)
        				arr[c] = 1;
    			}
    		}
    	}

    	return true;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	bool ret;
	Solution* ps = new Solution;
	vector<vector<char>> v = {
			  {'5','3','.','.','7','.','.','.','.'},
			  {'6','.','.','1','9','5','.','.','.'},
			  {'.','9','8','.','.','.','.','6','.'},
			  {'8','.','.','.','6','.','.','.','3'},
			  {'4','.','.','8','.','3','.','.','1'},
			  {'7','.','.','.','2','.','.','.','6'},
			  {'.','6','.','.','.','.','2','8','.'},
			  {'.','.','.','4','1','9','.','.','5'},
			  {'.','.','.','.','8','.','.','7','9'}};
	ret = ps->isValidSudoku(v);
	cout<<"ret="<<ret<<"\n";
	vector<vector<char>> v2 = {
			  {'8','3','.','.','7','.','.','.','.'},
			  {'6','.','.','1','9','5','.','.','.'},
			  {'.','9','8','.','.','.','.','6','.'},
			  {'8','.','.','.','6','.','.','.','3'},
			  {'4','.','.','8','.','3','.','.','1'},
			  {'7','.','.','.','2','.','.','.','6'},
			  {'.','6','.','.','.','.','2','8','.'},
			  {'.','.','.','4','1','9','.','.','5'},
			  {'.','.','.','.','8','.','.','7','9'} };
	ret= ps->isValidSudoku(v2);
	cout<<"ret="<<ret<<"\n";
	vector<vector<char>> v3 = {{'.','.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'}};
	ret= ps->isValidSudoku(v3);
	cout<<"ret="<<ret<<"\n";
}
