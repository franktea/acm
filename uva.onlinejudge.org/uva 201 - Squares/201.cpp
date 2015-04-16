/*
 * 201.cpp
 *
 *	uva 201 - Squares
 *
 *  Created on: Feb 19, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <string.h> // for bzero

using namespace std;
/**
 用两个数组，数组H[i][j][j]和V[i][j][k]， i,j,k取值区间[1, n]，并且j < k。
 H[i][j][k]表示水平第i行的第j与k两列是否连通，连通赋值为1，否则为0；
 V[i][j][k]表示垂直第i列的第j与k两行是否连通。

 这题的数据输入输出量较大，用scanf和printf以后时间会减少50％。
 */

const int32_t MAX_DOT_COUNT = 10; // 2 <= n <= 9

class SquareFinder
{
public:
	SquareFinder(int32_t dot_count): dot_count_(dot_count)
	{
		bzero(H, sizeof(H));
		bzero(V, sizeof(V));
	}

	inline void AddH(int32_t row, int32_t dot_index)
	{
		H[row][dot_index][dot_index+1] = 1;
	}

	inline void AddV(int32_t column, int32_t dot_index)
	{
		V[column][dot_index][dot_index+1] = 1;
	}

	void Solve()
	{
		bool has_squres = false; // 是否至少有一个正方形，没有要输出一句话
		for(int32_t s = 1; s <= dot_count_ - 1; ++s) // 需要查找的正方形的边长
		{
			int32_t s_count = 0; // 边长为s的正方形累计个数
			for(int32_t i = 1; i <= dot_count_ - s; ++i) // 第i行
			{
				for(int32_t j = 1; j <= dot_count_ - s; ++j) // 第j列
				{
					// 要查看点(i, j)与(i+s, j+s)外层的四边是否连通
					// 只要看点(i, j)与(i+s-1, j+s-1)、并且(i+s-1, j+s-1)与(i+s, j+s)是否连通即可
					if(i+s > dot_count_ || j+s > dot_count_)
						continue;

					if(Check(i, j, s))
						++ s_count;
				}
			}
			if(s_count > 0)
			{
				has_squres = true;
				cout<<s_count<<" square (s) of size "<<s<<"\n";
			}
		}

		if(! has_squres)
			cout<<"No completed squares can be found.\n";
	}
private:
	inline bool Check(const int32_t i, const int32_t j, const int32_t s)
	{
//		for(int32_t x = j+1; x <= j+s; ++x)
//		{
//			if(!H[i][x-1][x] || !H[i+s][x-1][x]) return false;
//		}
//
//		for(int32_t x=i+1; x <= i+s; ++x)
//		{
//			if(!V[j][x-1][x] || !V[j+s][x-1][x]) return false;
//		}
//
//		return true;

		// 下面的O(1)的判断方法居然比上面O(N)的提交以后更耗时？
		if(s == 1) return H[i][j][j+1] && H[i+1][j][j+1] &&
				V[j][i][i+1] && V[j+1][i][i+1];

		H[i][j][j+s] = H[i][j][j+s-1] && H[i][j+s-1][j+s];
		V[j][i][i+s] = V[j][i][i+s-1] && V[j][i+s-1][i+s];
		H[i+s][j][j+s] = H[i+s][j][j+s-1] && H[i+s][j+s-1][j+s];
		V[j+s][i][i+s] = V[j+s][i][i+s-1] && V[j+s][i+s-1][i+s];

		return H[i][j][j+s] && H[i+s][j][j+s] &&
				V[j][i][i+s] && V[j+s][i][i+s];
	}
private:
	const int32_t dot_count_; // 正方形边长共有多少个点
	int32_t H[MAX_DOT_COUNT][MAX_DOT_COUNT][MAX_DOT_COUNT];
	int32_t V[MAX_DOT_COUNT][MAX_DOT_COUNT][MAX_DOT_COUNT];
};

int main()
{
	// 加上这2句以后cin和cout会快50%，
	// 但是对本题来说， 速度可以与scanf和printf一样， 见201_2.cpp。
	// 对于运行时间稍微长的程序，就算是完全相同的代码，
	// 每次提交运行时间也会稍许差别(对本题来说差距会有10ms!)，
	// 估计是uva服务器性能一般。
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int32_t dot_count;
	int32_t prob_count = 0;
	while(cin>>dot_count)
	{
		++ prob_count;
		if(prob_count > 1) cout<<"\n**********************************\n\n";
		cout<<"Problem #"<<prob_count<<"\n\n";
		SquareFinder sf(dot_count);
		int32_t lines;
		cin>>lines;
		while(lines--)
		{
			char type; int32_t x, y;
			cin>>type>>x>>y;
			if(type == 'H') sf.AddH(x, y);
			if(type == 'V') sf.AddV(x, y);
		}
		sf.Solve();
	}

	return 0;
}

