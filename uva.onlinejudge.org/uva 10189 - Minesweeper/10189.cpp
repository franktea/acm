/*
 * 10189.cpp
 *
 *	uva 10189 - Minesweeper
 *
 *  Created on: Jun 7, 2015
 *      Author: frank
 */

#include <stdint.h>
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

using namespace std;

template <typename T, size_t N>
char (&ArraySizeHelper(T (&array)[N]))[N];
#define arraysize(array) (sizeof(ArraySizeHelper(array)))

class MineArray
{
public:
	MineArray(int32_t rows, int32_t cols) : rows_(rows),cols_(cols)
	{
		data_.resize(rows_);
	}

	void Init()
	{
		for(int32_t i = 0; i < rows_; ++i)
		{
			cin>>data_[i];
		}
	}

	void OutPut()
	{
		const int32_t delta_x[] = {-1, -1, -1, 0, 1, 1, 1, 0};
		const int32_t delta_y[] = {-1, 0, 1, 1, 1, 0, -1, -1};
		static_assert(arraysize(delta_x) == arraysize(delta_y), "array size not equal");
		for(int32_t row = 0; row < rows_; ++row)
		{
			for(int32_t col = 0; col < cols_; ++col)
			{
				if(data_[row][col] == '*')
				{
					cout<<'*';
					continue;
				}

				int32_t sum = 0;
				for(int32_t i = 0; i < arraysize(delta_x); ++i)
				{
					int32_t x = row + delta_x[i];
					int32_t y = col + delta_y[i];
					if(x < 0 || x >= rows_ || y < 0 || y >= cols_)
					{
						continue;
					}
					if(data_[x][y] == '*')
					{
						++sum;
					}
				}
				cout<<sum;
			}
			cout<<"\n";
		}
	}
private:
	int32_t rows_;
	int32_t cols_;
	vector<string> data_;
};

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int32_t rows, cols;
	int32_t case_count = 0;
	while(cin>>rows>>cols)
	{
		if(rows == 0 || cols == 0) break;
		if(++case_count > 1) cout<<"\n";
		MineArray ma(rows, cols);
		ma.Init();
		cout<<"Field #"<<case_count<<":\n";
		ma.OutPut();
	}
	return 0;
}
