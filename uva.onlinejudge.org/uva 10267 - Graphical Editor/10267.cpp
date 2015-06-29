/*
 * 10267.cpp
 *
 *	uva 10267 - Graphical Editor
 *
 *  Created on: Jun 28, 2015
 *      Author: frank
 */

#include <stdint.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

const int32_t max_size = 251;

char data[max_size][max_size];
bool visited[max_size][max_size];
int32_t cols = 0;
int32_t rows = 0;

int32_t delta_x[] = {0, 1, 0, -1};
int32_t delta_y[] = {-1, 0, 1, 0};

void FindAndChange(char old_color, char new_color, int32_t x, int32_t y)
{
	data[x][y] = new_color;
	visited[x][y] = true;
	for(int32_t i = 0; i < 4; ++i)
	{
		int32_t new_x = x + delta_x[i];
		int32_t new_y = y + delta_y[i];
		if(new_x < 1 || new_x > cols || new_y < 1 || new_y > rows)
			continue;

		if(visited[new_x][new_y])
			continue;

		if(data[new_x][new_y] != old_color)
			continue;

		FindAndChange(old_color, new_color, new_x, new_y);
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	string line;
	while(std::getline(cin, line))
	{
		char cmd;
		switch(line[0])
		{
		case 'I':
		{
			stringstream ss(line);
			ss>>cmd>>cols>>rows;
			memset(data, 'O', sizeof(data));
		}
			break;
		case 'C':
			memset(data, 'O', sizeof(data));
			break;
		case 'L':
		{
			int32_t x, y;
			char color;
			stringstream ss(line);
			ss>>cmd>>x>>y>>color;
			data[x][y] = color;
		}
			break;
		case 'V':
		{
			int32_t x, y1, y2;
			char color;
			stringstream ss(line);
			ss>>cmd>>x>>y1>>y2>>color;
			if(y2 < y1)
				std::swap(y1, y2);

			for(int32_t y = y1; y <= y2; ++y)
				data[x][y] = color;
		}
			break;
		case 'H':
		{
			int32_t x1, x2, y;
			char color;
			stringstream ss(line);
			ss>>cmd>>x1>>x2>>y>>color;
			if(x2 < x1)
				std::swap(x1, x2);

			for(int32_t x = x1; x <= x2; ++x)
				data[x][y] = color;
		}
			break;
		case 'K':
		{
			int32_t x1, x2, y1, y2;
			char color;
			stringstream ss(line);
			ss>>cmd>>x1>>y1>>x2>>y2>>color;
			if(x2 < x1)
				std::swap(x1, x2);
			if(y2 < y1)
				std::swap(y1, y2);

			for(int32_t x = x1; x <= x2; ++x)
				for(int32_t y = y1; y <= y2; ++y)
					data[x][y] = color;
		}
			break;
		case 'F':
		{
			int32_t x, y;
			char color;
			stringstream ss(line);
			ss>>cmd>>x>>y>>color;
			bzero(visited, sizeof(visited));
			FindAndChange(data[x][y], color, x, y);
		}
			break;
		case 'S':
		{
			string file_name;
			stringstream ss(line);
			ss>>cmd>>file_name;
			cout<<file_name<<"\n";
			for(int32_t y = 1; y <= rows; ++y)
			{
				for(int32_t x = 1; x <= cols; ++x)
				{
					cout<<data[x][y];
				}
				cout<<"\n";
			}
		}
			break;
		case 'X':
		{
			return 0;
		}
			break;
		default:
			break;
		}
	}
	return 0;
}

