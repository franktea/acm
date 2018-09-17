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

    	for(vector<char>& v: board)
    	{
    		for(char& c: v)
    			cout<<int(c)<<", ";
    		cout<<"\n";
    	}

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

    	for(const Cell& cell: cells_)
    		cout<<cell.ToString()<<"\n";

    	return DFS(board, 0);

    	return true;
    }
private:
    bool DFS(vector<vector<char>>& board, int index)
    {
    	if(index >= cells_.size()) // finished
    		return true;

    	Cell& cell = cells_[index];
    	for(int x = 0; x < cell.candinates.size(); ++x)
    	{
    		board[cell.i][cell.j] = cell.candinates[x];
    		if(! Check(board, cell.i, cell.j))
    			continue;

    		bool ret = DFS(board, index+1);
    		if(ret)
    			return true;
    		board[cell.i][cell.j] = 0;
    	}

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
    		std::bitset<9> bits;
    		const vector<char>& v = board[i];
    		for(int value: v)
    		{
    			if(value && bits[value-1])
    				return false;

    			if(value)
    				bits.set(value);
    		}
    	}

    	//check column
    	{
    		std::bitset<9> bits;
			for(const vector<char>& v: board)
			{
				if(v[j] && bits[v[j]-1])
					return false;

				if(v[j])
					bits.set(v[j]-1);
			}
    	}

    	// check 3x3 sub box
    	{
    		std::bitset<9> sub;
    		const int sub_row = i / 3;
    		const int sub_col = j / 3;
    		for(int row = sub_row; row < sub_row+3; ++row)
    		{
    			for(int col = sub_col; col < sub_col+3; ++col)
    			{
    				if(board[row][col] && sub[board[row][col]-1])
    					return false;

    				if(board[row][col])
    					sub.set(board[row][col]-1);
    			}
    		}
    	}

    	return true;
    }
private:
    vector<Cell> cells_; // empty cells to fill
};

int main()
{
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
	Solution* ps = new Solution;
	bool ret = ps->isValidSudoku(v);
	cout<<"ret="<<ret<<"\n";
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
}
