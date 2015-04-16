/*
 * 371.cpp
 *
 *  Created on: Mar 2, 2015
 *      Author: frank
 */

#include <iostream>
#include <algorithm> // for std::swap, std::max
#include <stdint.h>
#include <vector>

using namespace std;

/**
 * 虽然和100很象，但是还是有区别。
 * 路径长度不包括自身, 但是在100中要包括；
 * 还有和100不同的是，对于数字1要区别对待，要把1看成奇数，要先乘3＋1，1的路径长度为3；
 */

// 缓存100w个
vector<int64_t> cached(1000001, 0);

int64_t Steps(int64_t n)
{
	if(n < cached.size() && cached[n]) return cached[n];

	if(n <= 1) return 0;

	n = (n % 2) ? (3*n + 1) : n/2;
	int64_t result = Steps(n);
	if(n < cached.size()) cached[n] = result;

	return 1 + result;
}

int main()
{
	int64_t start, end;
	while(cin>>start>>end)
	{
		if(start == 0 && end == 0) break;

		int64_t max_steps = 0;
		int64_t start2 = start, end2 = end;
		if(start2 > end2) std::swap(start2, end2);//交换一下
		int64_t max_n = start2;
		for(int64_t n = start2; n <= end2; ++n)
		{
			const int64_t t = (n==1)? 3 : Steps(n);
			if(max_steps < t)
			{
				max_steps = t;
				max_n = n;
			}
		}
		cout<<"Between "<<start2<<" and "<<end2<<", "<<max_n<<" generates the longest sequence of "<<max_steps<<" values.\n";
	}
	return 0;
}


