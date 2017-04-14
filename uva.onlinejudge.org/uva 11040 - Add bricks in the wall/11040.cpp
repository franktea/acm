/*
 * 11040.cpp
 *	uva 11040 - Add bricks in the wall
 *  Created on: Apr 15, 2017
 *      Author: frank
 */
#include <vector>
#include <iostream>
#include <stdint.h>
using namespace std;

class Bricks
{
public:
	Bricks()
	{
		triangle.resize(9);
		for(size_t i = 0; i < 9; ++i)
		{
			triangle[i].resize(i+1);
		}
	}

	void Input()
	{
		cin>>triangle[0][0];
		cin>>triangle[2][0]>>triangle[2][2];
		cin>>triangle[4][0]>>triangle[4][2]>>triangle[4][4];
		cin>>triangle[6][0]>>triangle[6][2]>>triangle[6][4]>>triangle[6][6];
		cin>>triangle[8][0]>>triangle[8][2]>>triangle[8][4]>>triangle[8][6]>>triangle[8][8];
	}

	void Calc()
	{
		for(int32_t row = 8; row >= 0; --row)
		{
			if(row % 2 == 0)
			{
				for(int32_t col = 1; col < row; col += 2)
				{
					triangle[row][col] = (triangle[row-2][col-1] - triangle[row][col-1] - triangle[row][col+1])/2;
				}
			}
			else
			{
				for(int32_t col = 0; col <= row; ++col)
				{
					triangle[row][col] = triangle[row+1][col] + triangle[row+1][col+1];
				}
			}
		}
	}

	void OutPut()
	{
		for(size_t row = 0; row < 9; ++row)
		{
			for(size_t col = 0; col <= row; ++col)
			{
				if(col > 0) cout<<" ";
				cout<<triangle[row][col];
			}
			cout<<"\n";
		}
	}
private:
	vector<vector<int32_t>> triangle;
};

int main()
{
	int32_t case_count;
	cin>>case_count;
	while(case_count--)
	{
		Bricks bricks;
		bricks.Input();
		bricks.Calc();
		bricks.OutPut();
	}
	return 0;
}



