/*
 * 79.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 用递归的方法, 递归的深度就是需要搜索的字符串的长度

static const int dx[] = {0, 1, 0, -1};
static const int dy[] = {-1, 0, 1, 0};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	if(board.empty()) return false;
    	if(word.empty()) return true;

    	const int width = board[0].size();
    	const int height = board.size();

    	visited_.resize(height);
    	for(vector<int>& v: visited_)
    		v.resize(width, 0);

    	for(int x = 0; x < width; ++x)
    		for(int y = 0; y < height; ++y)
    		{
    			if(board[y][x] == word[0])
    			{
    				if(Find(board, word, 0, x, y))
    					return true;
    			}
    		}

    	return false;
    }
private:
    bool Find(vector<vector<char>>& board, const string& word, int index, int x, int y)
    {
    	if(index == word.size())
    	{
    		return true;
    	}

		if(x < 0 || x >= int(board[0].size()) || y < 0 || y >= int(board.size()))
		{
			return false;
		}

		if(visited_[y][x])
			return false;

    	if(board[y][x] != word[index])
    		return false;

    	bool result = false;
    	visited_[y][x] = 1;
    	for(int i = 0; i < 4; ++i)
    	{
    		int x2 = x + dx[i];
    		int y2 = y + dy[i];

    		result = Find(board, word, index + 1, x2, y2);
    		if(result)
    			break;
    	}
    	visited_[y][x] = 0; // 每次递归完毕以后都清除visite状态

    	return result;
    }
private:
    vector<vector<int>> visited_;
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<vector<char>> v = {{'a'}};//{{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
	string word = "a";
	Solution* ps = new Solution;
	bool ret = ps->exist(v, word);
	cout<<"ret="<<ret<<"\n";
	return 0;
}


