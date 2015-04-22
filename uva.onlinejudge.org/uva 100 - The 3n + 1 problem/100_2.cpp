/*
 * 100_2.cpp
 *
 *  uva 100 - The 3n + 1 problem
 *
 *  Created on: Feb 1, 2015
 *      Author: frank
 */


#include <iostream>
#include <algorithm> // for std::swap, std::max
#include <stdint.h>
#include <vector>

using namespace std;

// 缓存100w个
vector<int64_t> cached(1000001, 0);

int64_t Steps(int64_t n)
{
	if(n < cached.size() && cached[n]) return cached[n];

	if(n <= 1) return 1;

	n = (n % 2) ? (3*n + 1) : n/2;
	int64_t result = Steps(n);
	if(n < cached.size()) cached[n] = result;

	return 1 + result;
}

int main()
{
	int64_t start, end;
	while(cin>>start>>end) //坑爹：每行2个数字，但是前面的不一定比后面的数字小，要注意！
	{
		int64_t max_steps = 0;
		int64_t start2 = start, end2 = end;
		if(start2 > end2) std::swap(start2, end2);//交换一下
		for(int64_t n = start2; n <= end2; ++n)
		{
			max_steps = std::max(max_steps, Steps(n));
		}
		cout<<start<<" "<<end<<" "<<max_steps<<"\n";
	}
	return 0;
}

