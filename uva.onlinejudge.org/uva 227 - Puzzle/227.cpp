/*
 * 227.cpp
 *
 *	uva 227 - Puzzle
 *
 *  Created on: Feb 21, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <string>
#include <string.h>
#include <assert.h>
#include <algorithm>

using namespace std;

/**
 * 注意事项：由于行首可能含有合法的空格，所以最好不要用cin，全部用getline；
 * 命令可能有多行，如果其中的某一行含有非法的命令，必须继续将后面的命令全部读取完，
 * 否则会被当成下一个case的矩阵数据！
 */

const int32_t SQUQRE_SIZE = 5;

const int32_t A_delta_x = -1;
const int32_t A_delta_y = 0;
const int32_t B_delta_x = 1;
const int32_t B_delta_y = 0;
const int32_t L_delta_x = 0;
const int32_t L_delta_y = -1;
const int32_t R_delta_x = 0;
const int32_t R_delta_y = 1;

#define MOVE_CMD(CMD) 				int32_t x = blankx_ + CMD##_delta_x; \
int32_t y = blanky_ + CMD##_delta_y; \
if(x < 0 || x >= SQUQRE_SIZE || y < 0 || y >= SQUQRE_SIZE) \
{ \
	valid = false; \
	goto lable; \
} \
std::swap(square_[x][y], square_[blankx_][blanky_]); \
blankx_ = x; \
blanky_ = y;

class Puzzle
{
public:
	Puzzle():blankx_(0), blanky_(0)
	{
		bzero(square_, sizeof(square_));
	}

	void Init(string& line)
	{
		for(int32_t i = 0; i < SQUQRE_SIZE; ++i)
		{
			if(i > 0) std::getline(cin, line);
			if(line.length() != SQUQRE_SIZE) cout<<"line is:::::"<<line<<endl;
			assert(line.length() == SQUQRE_SIZE);
			for(int32_t j = 0; j < line.length(); ++j)
			{
				square_[i][j] = line[j];
				if(square_[i][j] == ' ')
				{
					blankx_ = i;
					blanky_ = j;
				}
			}
		}
	}

	void Run()
	{
		string line;
		char cmd;
		bool valid = true;
		while(getline(cin, line))
		{
			for(char cmd: line)
			{
				if('0' == cmd) goto lable;
				if('A' == cmd) { MOVE_CMD(A) }
				else if('B' == cmd) { MOVE_CMD(B) }
				else if('L' == cmd) { MOVE_CMD(L) }
				else { MOVE_CMD(R) }
			}
		}

		lable: // 跳出双重循环
		if(valid) OutPut();
		else //注意：非法退出的，可能命令根本就没有输入完成！必须将剩下的命令也要全部读出来，否则会被当成后面的矩阵数据
		{
			while(line.find('0') == string::npos) getline(cin, line);
			cout<<"This puzzle has no final configuration.\n";
		}
	}

	void OutPut()
	{
		for(int32_t i = 0; i < SQUQRE_SIZE; ++i)
		{
			for(int32_t j = 0; j < SQUQRE_SIZE; ++j)
			{
				if(j == 0) cout<<square_[i][j];
				else cout<<" "<<square_[i][j];
			}
			cout<<"\n";
		}
	}
private:
	int32_t blankx_;
	int32_t blanky_;
	char square_[SQUQRE_SIZE][SQUQRE_SIZE];
};

int main()
{
	int32_t case_count = 0;
	std::string line;
	while(std::getline(cin, line))
	{
		//if(line == "") continue;
		if(line[0] == 'Z') break;

		if(case_count > 0) cout<<"\n";
		cout<<"Puzzle #"<<++case_count<<":\n";
		Puzzle puzzle;
		puzzle.Init(line);
		puzzle.Run();
	}
	return 0;
}


