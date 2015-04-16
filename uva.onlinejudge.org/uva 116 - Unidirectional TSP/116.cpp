/*
 * 116.cpp
 *
 *	title: Unidirectional TSP
 *  http://uva.onlinejudge.org/external/1/116.html
 *
 *  Created on: Feb 5, 2015
 *      Author: frank
 */

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <string.h> // for bzero
#include <stdio.h>

using namespace std;

//const int64_t MAX_ROWS = 11;
const int64_t MAX_ROWS = 15;
const int64_t MAX_COLS = 101;

int64_t matrix[MAX_ROWS][MAX_COLS];
int64_t minsum[MAX_ROWS][MAX_COLS]; // 第i列到目前为止最小的和, 1<=i<=n
int64_t column[MAX_ROWS][MAX_COLS]; // 与matrix[i][j]位置对应的最小的和时上一列的位置（行数）

class MinElementHelper
{
public:
	MinElementHelper(const int64_t row_count, const int64_t col_count):
		total_row_count(row_count), total_col_count(col_count)
        {
	        bzero(minsum, sizeof(minsum));
	        bzero(column, sizeof(column));
        }
public:
	struct MinData
	{
		int64_t row_index;
		int64_t min_element;
		//int64_t real;

		bool operator<(const MinElementHelper::MinData& rhs)
		{
			return this->min_element < rhs.min_element ||
					//(this->min_element == rhs.min_element && this->real > rhs.real);
			        // 字典顺序。。。。。
			        (this->min_element == rhs.min_element && this->row_index < rhs.row_index);
		}
	};

	void FindMinOfColumn(const int64_t row, const int64_t col)
	{
		if(col == total_col_count)
		{
			minsum[row][col] = matrix[row][col];
			//cout<<"min("<<row<<", "<<col<<") = "<<minsum[row][col]<<endl;
			return;
		}

		const MinData& min_data = MinElement(row, col);
		minsum[row][col] = matrix[row][col] + min_data.min_element;
		column[row][col] = min_data.row_index;

		//cout<<"min("<<row<<", "<<col<<") = "<<minsum[row][col]<<"; min("<<row<<", "<<col+1<<") ="
		//		<<minsum[row][col+1]<<endl;
	}
private:
	const MinData& MinElement(const int64_t current_row, const int64_t current_col)
	{
		TopRight(current_row, current_col);
		Right(current_row, current_col);
		BottomRight(current_row, current_col);
		MinData& result = top_right_;
		if(right_ < result) result = right_;
		if(bottom_right_ < result) result = bottom_right_;

		return result;
	}

	void TopRight(const int64_t current_row, const int64_t current_col)
	{
		top_right_.row_index = current_row - 1;
		//top_right_.real = 1;
		if(top_right_.row_index < 1)
		{
			top_right_.row_index = total_row_count;
			//top_right_.real = 0;
		}
		top_right_.min_element = minsum[top_right_.row_index][current_col+1];
	}

	void Right(const int64_t current_row, const int64_t current_col)
	{
		right_.row_index = current_row;
		//right_.real = 1;
		right_.min_element = minsum[right_.row_index][current_col+1];
	}

	void BottomRight(const int64_t current_row, const int64_t current_col)
	{
		bottom_right_.row_index = current_row + 1;
		//bottom_right_.real = 1;
		if(bottom_right_.row_index > total_row_count)
		{
			bottom_right_.row_index = 1;
			//bottom_right_.real = 0;
		}
		bottom_right_.min_element = minsum[bottom_right_.row_index][current_col+1];
	}
private:
	const int64_t total_row_count;
	const int64_t total_col_count;
	MinData top_right_;
	MinData right_;
	MinData bottom_right_;
//public:
//	int64_t minsum[MAX_ROWS][MAX_COLS]; // 第i列到目前为止最小的和, 1<=i<=n
//	int64_t column[MAX_ROWS][MAX_COLS]; // 与matrix[i][j]位置对应的最小的和时上一列的位置（行数）
};

void FindMin(const int64_t m, const int64_t n) // m rows and n colomns
{
	MinElementHelper helper(m, n);
	//bzero(minsum, sizeof(minsum));
	//bzero(column, sizeof(column));
	for(int64_t j = n; j >= 1; --j)
	{
		for(int64_t i = 1; i <= m; ++i)
		{
			helper.FindMinOfColumn(i, j);
		}
	}

	int64_t min_sum = minsum[1][1];
	int64_t min_row_index = 1;
	for(int64_t i = 2; i <= m; ++i)
	{
		if(minsum[i][1] < min_sum)
		{
			min_sum = minsum[i][1];
			min_row_index = i;
		}
	}

	cout<<min_row_index;
	for(int j = 1; j < n; ++j)
	{
		cout<<" "<<column[min_row_index][j];
		min_row_index = column[min_row_index][j];
	}
	cout<<"\n"<<min_sum<<"\n";
}

int main()
{
	int64_t m, n;
	while(cin>>m>>n)
	{
		for(int64_t i = 1; i <= m; ++i)
		{
			for(int64_t j = 1; j <= n; ++j)
			{
				cin>>matrix[i][j];
			}
		}
		FindMin(m, n);
	}
	return 0;
}


