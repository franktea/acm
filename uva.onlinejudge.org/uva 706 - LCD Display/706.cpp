/*
 * 706.cpp
 *
 * uva 706 - LCD Display
 *
 *  Created on: Jun 28, 2015
 *      Author: frank
 */

#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

/**
 * 输出数字的第1部分，piece_count是最终需要显示的大小，对于每个数字，
 * 这个函数都要调用piece_count次。
 * @param number 需要显示的数字
 * @param piece_count 需要显示的数字的大小
 * @param piece_index 表示当前是第几次调用此函数，范围［0， piece_count-1]
 */
void Part1(const int32_t number, const int32_t piece_count, const int32_t piece_index)
{
	switch(number)
	{
	case 0:
	case 2:
	case 3:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		if(piece_index == 0) cout<<" ";
		cout<<"-";
		if(piece_index == piece_count - 1) cout<<" ";
		break;
	case 1:
	case 4:
		if(piece_index == 0) cout<<" ";
		cout<<" ";
		if(piece_index == piece_count - 1) cout<<" ";
		break;
	default:
		break;
	}
}

void Part2(const int32_t number, const int32_t piece_count, const int32_t piece_index)
{
	switch(number)
	{
	case 0:
	case 4:
	case 8:
	case 9:
		if(piece_index == 0) cout<<"|";
		cout<<" ";
		if(piece_index == piece_count - 1) cout<<"|";
		break;
	case 1:
	case 2:
	case 3:
	case 7:
		if(piece_index == 0) cout<<" ";
		cout<<" ";
		if(piece_index == piece_count - 1) cout<<"|";
		break;
	case 5:
	case 6:
		if(piece_index == 0) cout<<"|";
		cout<<" ";
		if(piece_index == piece_count - 1) cout<<" ";
		break;
	default:
		break;
	}
}

void Part3(const int32_t number, const int32_t piece_count, const int32_t piece_index)
{
	switch(number)
	{
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 8:
	case 9:
		if(piece_index == 0) cout<<" ";
		cout<<"-";
		if(piece_index == piece_count - 1) cout<<" ";
		break;
	case 0:
	case 1:
	case 7:
		if(piece_index == 0) cout<<" ";
		cout<<" ";
		if(piece_index == piece_count - 1) cout<<" ";
		break;
	default:
		break;
	}
}

void Part4(const int32_t number, const int32_t piece_count, const int32_t piece_index)
{
	switch(number)
	{
	case 0:
	case 6:
	case 8:
		if(piece_index == 0) cout<<"|";
		cout<<" ";
		if(piece_index == piece_count - 1) cout<<"|";
		break;
	case 2:
		if(piece_index == 0) cout<<"|";
		cout<<" ";
		if(piece_index == piece_count - 1) cout<<" ";
		break;
	case 1:
	case 3:
	case 4:
	case 5:
	case 7:
	case 9:
		if(piece_index == 0) cout<<" ";
		cout<<" ";
		if(piece_index == piece_count - 1) cout<<"|";
		break;
	default:
		break;
	}
}

void Part5(const int32_t number, const int32_t piece_count, const int32_t piece_index)
{
	switch(number)
	{
	case 0:
	case 2:
	case 3:
	case 5:
	case 6:
	case 8:
	case 9:
		if(piece_index == 0) cout<<" ";
		cout<<"-";
		if(piece_index == piece_count - 1) cout<<" ";
		break;
	case 1:
	case 4:
	case 7:
		if(piece_index == 0) cout<<" ";
		cout<<" ";
		if(piece_index == piece_count - 1) cout<<" ";
		break;
	default:
		break;
	}
}

#define Print(n) 		for(int32_t i = 0; i < numbers.size(); ++i) \
{ \
	for(int32_t j = 0; j < piece_count; ++j) \
	{ \
		Part##n(numbers[i] - '0', piece_count, j); \
	} \
	if(i != numbers.size()-1) \
	{ \
		cout<<" "; \
	} \
	else \
	{ \
		cout<<"\n"; \
	} \
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int32_t piece_count;
	while(cin>>piece_count)
	{
		if(0 == piece_count)
			break;

		string numbers;
		cin>>numbers;
		// cout<<piece_count<<":"<<numbers<<"\n";

		Print(1)
		for(int32_t k = 0; k < piece_count; ++k)
			Print(2)
		Print(3)
		for(int32_t k = 0; k < piece_count; ++k)
			Print(4)
		Print(5)
		cout<<"\n";
	}
	return 0;
}

