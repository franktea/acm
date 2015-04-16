/*
 * 151.cpp
 *
 * 151 of http://uva.onlinejudge.org
 *
 *  Created on: Feb 1, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>

using namespace std;

const size_t MAX_N = 101;

int32_t arr[MAX_N];

inline int32_t NextIndex(const int32_t N, const int32_t current_index)
{
	int32_t next_index = current_index + 1;
	if(next_index > N) next_index = 1;
	while(! arr[next_index])
	{
		next_index = next_index + 1;
		if(next_index > N) next_index = 1;
		if(next_index == current_index) break;
	}
	return next_index;
}

bool CheckM(const int32_t N, const int32_t m)
{
	int32_t next_index = 1;
	arr[next_index] = 0;
	int32_t left = N - 1;
	while(left > 1)
	{
		for(int32_t i = 0; i < m; ++i)
		{
			next_index = NextIndex(N, next_index);
		}
		arr[next_index] = 0;
		-- left;
	}
	// now there is only one left, check if it's 13
	next_index = NextIndex(N, next_index);
	return (13 == next_index);
}

void Settle(const int32_t N)
{
	for(int32_t i = 1; i <= N; ++i)
	{
		arr[i] = i;
	}

	int32_t current_m = 1;
	while(! CheckM(N, current_m))
	{
		++ current_m;
		for(int32_t i = 1; i <= N; ++i)
		{
			arr[i] = i;
		}
	}

	cout<<current_m<<"\n";
}

int main()
{
	int32_t N;
	while(cin>>N)
	{
		if(0 == N) break;
		Settle(N);
	}
	return 0;
}


