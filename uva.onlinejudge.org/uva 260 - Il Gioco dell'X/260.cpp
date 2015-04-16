/*
 * 260.cpp
 *
 *	uva 260 - Il Gioco dell'X
 *
 *  Created on: Feb 23, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <string.h> // for bzero

using namespace std;

/**
 * 简单的dfs，这个游戏看样子还很好玩。
 * 虽然是一次ac的，但是这点代码也写了40分钟。
 */

const int32_t MAXLEN = 201;
const int32_t delta_x[] = {-1, -1, 0, 0, 1, 1};
const int32_t delta_y[] = {-1, 0, -1, 1, 0, 1};

bool Solve(char data[][MAXLEN], bool visited[][MAXLEN],
		const int32_t length,
		const int32_t row, const int32_t col)
{
	visited[row][col] = true;

	if(row >= length)
	{
		return data[row][col] == 'b';
	}

	for(int32_t i = 0; i < 6; ++i)
	{
		const int32_t next_row = row + delta_x[i];
		const int32_t next_col = col + delta_y[i];
		if(next_row < 1 || next_row > length ||
				next_col < 1 || next_col > length)
		{
			continue;
		}

		if(visited[next_row][next_col] || 'b' != data[next_row][next_col])
		{
			continue;
		}

		if(Solve(data, visited, length, next_row, next_col))
		{
			return true;
		}
	}
	return false;
}

//题目说了必有胜负，只用检查黑方是否赢了，如果没赢肯定就是白方赢
bool CheckBlack(char data[][MAXLEN], bool visited[][MAXLEN],
		const int32_t length)
{
	for(int32_t col = 1; col <= length; ++col)
	{
		if('b' == data[1][col] && !visited[1][col] &&
				Solve(data, visited, length, 1, col))
		{
			return true;
		}
	}

	return false;
}


int main()
{
	char data[MAXLEN][MAXLEN];
	bool visited[MAXLEN][MAXLEN];
	int32_t length;
	int32_t count = 0;
	while(cin>>length)
	{
		if(0 == length) break;
		++count;
		bzero(data, sizeof(data));
		bzero(visited, sizeof(visited));
		for(int32_t i = 1; i <= length; ++i)
			for(int32_t j = 1; j <= length; ++j)
				cin>>data[i][j];
		cout<<count<<" ";
		if(CheckBlack(data, visited, length)) cout<<"B\n";
		else cout<<"W\n";
	}
}


