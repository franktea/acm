/*
 * 572.cpp
 *
 *	uva 572 - Oil Deposits
 *
 *  Created on: Mar 2, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <stdint.h>

/**
 * 数有多少片连续的相连的@，与数水洼（poj2386）类似，
 * 每个可以与周围8个方向连续。
 * 与uva 352、469也类似。
 */

using namespace std;

template<typename T, std::size_t N>
std::size_t array_size(T(&)[N])
{
	return N;
}

const int32_t DX[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int32_t DY[] = {-1, 0, 1, 1, 1, 0, -1, -1};

class Matrix
{
public:
	Matrix(int32_t N, int32_t M): N_(N), M_(M)
	{
		data_.resize(N_*M_);
	}

	int32_t Count()
	{
		int32_t result = 0;
		for(int32_t x = 0; x < N_; ++x)
		{
			for(int32_t y = 0; y < M_; ++y)
			{
				if(Value(x, y) == '@')
				{
					++ result;
					DFS(x, y);
				}
			}
		}
		return result;
	}

	char& Value(int32_t x, int32_t y)
	{
		return data_[x*M_+y];
	}
private:
	void DFS(int32_t x, int32_t y)
	{
		Value(x, y) = '*';

		for(size_t i = 0; i < array_size(DX); ++i)
		{
			int32_t x1 = x + DX[i];
			int32_t y1 = y + DY[i];
			if(Valid(x1, y1) && (Value(x1, y1) == '@'))
			{
				DFS(x1, y1);
			}
		}
	}

	bool Valid(int32_t x, int32_t y)
	{
		return x >= 0 && x < N_ &&
				y >= 0 && y < M_;
	}
private:
	const int32_t N_;
	const int32_t M_;
	vector<char> data_;
};

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int32_t N, M;
	while(cin>>N>>M)
	{
		if(N == 0 && M == 0) break;
		Matrix mm(N, M);
		char value;
		for(int32_t x = 0; x < N; ++x)
		{
			for(int32_t y = 0; y < M; ++y)
			{
				cin>>value;
				while(value != '@' && value != '*')
					cin>>value;
				mm.Value(x, y) = value;
			}
		}
		cout<<mm.Count()<<"\n";
	}

	return 0;
}




