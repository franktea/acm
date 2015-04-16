/*
 * 111.cpp
 *
 *  uva 111 History Grading
 *
 *  Created on: Feb 17, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <string.h> // for bzero
#include <algorithm> // for std::max

/**
 * 简单的lcs，题目的意思有点坑，这题的输入是个很大的坑，他的输入是按照顺序，
 * 事件1是排在第几位，事件2是排在第几位......， 所以要先把输入转换成正确的顺序。
 */
using namespace std;

const int32_t max_n = 21;
int32_t correct[max_n];
int32_t student[max_n];

int32_t dp[max_n][max_n];

void Lcs(const int32_t n)
{
	bzero(dp, sizeof(dp));
	for(int32_t i = 0; i <= n; ++i)
	{
		for(int32_t j = 0; j <= n; ++j)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}

			if(correct[i] == student[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
}

int main()
{
	int32_t n;
	cin>>n;
	bzero(correct, sizeof(correct));
	int32_t tmp;
	for(int32_t i = 1; i <= n; ++i)
	{
		cin>>tmp;
		correct[tmp] = i;
	}

	while(1)
	{
		bzero(student, sizeof(student));
		for(int32_t i = 1; i <= n; ++i)
		{
			if(! (cin>>tmp)) return 0;
			student[tmp] = i;
		}

		Lcs(n);
		cout<<dp[n][n]<<"\n";
	}

	return 0;
}


