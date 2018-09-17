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

using namespace std;

class Solution {
	struct Cell
	{
		int i;
		int j;
		std::vector<char> candinates;
		Cell(int x, int y):i(x), j(y){}
		string ToString() const
		{
			std::stringstream ss;
			ss<<"("<<i<<", "<<j<<"), cands=[";
			for(int i: candinates)
				ss<<i<<", ";
			ss<<"]";
			return ss.str();
		}
	};
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	for(vector<char>& v: board)
    		for(char& c: v)
    			c = c == '.' ? 0 : c - '0';

//    	for(vector<char>& v: board)
//    	{
//    		for(char& c: v)
//    			cout<<int(c)<<", ";
//    		cout<<"\n";
//    	}

    	for(int i = 0; i < board.size(); ++i)
    	{
    		for(int j = 0; j < board[0].size(); ++j)
    		{
    			if(board[i][j])
    				continue;

    			Cell cell(i, j);
    			cells_.push_back(cell);
    			CalcCell(board, cells_.back());
    		}
    	}

    	std::sort(cells_.begin(), cells_.end(), [](const Cell& lhs, const Cell& rhs){
    		return lhs.candinates.size() < rhs.candinates.size();
    	});

//    	for(const Cell& cell: cells_)
//    		cout<<cell.ToString()<<"\n";

    	bool ret = DFS(board, 0);

//		for(vector<char>& v: board)
//		{
//			for(char& c: v)
//				cout<<int(c)<<", ";
//			cout<<"\n";
//		}

    	return ret;
    }
private:
    bool DFS(vector<vector<char>>& board, int index)
    {
    	if(index >= cells_.size()) // finished
    		return true;

    	Cell& cell = cells_[index];
    	for(int value: cell.candinates)
    	{
    		board[cell.i][cell.j] = value;
    		if(! Check(board, cell.i, cell.j))
    			continue;

    		bool ret = DFS(board, index+1);
    		if(ret)
    			return true;
    		board[cell.i][cell.j] = 0;
    	}

    	board[cell.i][cell.j] = 0;
    	return false;
    }

    void CalcCell(vector<vector<char>>& board, Cell& cell)
    {
    	bitset<9> bits;
    	for(int c = 0; c < 9; ++c)
    	{
    		if(board[cell.i][c])
    		{
    			bits.set(board[cell.i][c]-1);
    		}

    		if(board[c][cell.j])
    		{
    			bits.set(board[c][cell.j]-1);
    		}
    	}

    	for(char i = 0; i < 9; ++i)
    	{
    		if(!bits[i])
    			cell.candinates.push_back(i+1);
    	}
    }

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
private:
    vector<Cell> cells_; // empty cells to fill
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	bool ret;
	Solution* ps = new Solution;
//	vector<vector<char>> v = {
//			  {'5','3','.','.','7','.','.','.','.'},
//			  {'6','.','.','1','9','5','.','.','.'},
//			  {'.','9','8','.','.','.','.','6','.'},
//			  {'8','.','.','.','6','.','.','.','3'},
//			  {'4','.','.','8','.','3','.','.','1'},
//			  {'7','.','.','.','2','.','.','.','6'},
//			  {'.','6','.','.','.','.','2','8','.'},
//			  {'.','.','.','4','1','9','.','.','5'},
//			  {'.','.','.','.','8','.','.','7','9'}};
//	ret = ps->isValidSudoku(v);
//	cout<<"ret="<<ret<<"\n";
//	vector<vector<char>> v2 = {
//			  {'8','3','.','.','7','.','.','.','.'},
//			  {'6','.','.','1','9','5','.','.','.'},
//			  {'.','9','8','.','.','.','.','6','.'},
//			  {'8','.','.','.','6','.','.','.','3'},
//			  {'4','.','.','8','.','3','.','.','1'},
//			  {'7','.','.','.','2','.','.','.','6'},
//			  {'.','6','.','.','.','.','2','8','.'},
//			  {'.','.','.','4','1','9','.','.','5'},
//			  {'.','.','.','.','8','.','.','7','9'} };
//	ret= ps->isValidSudoku(v2);
//	cout<<"ret="<<ret<<"\n";
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
