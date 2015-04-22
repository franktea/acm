/*
 * 100.cpp
 *
 * 100th of http://uva.onlinejudge.org
 *
 * title:
 * The 3n + 1 problem
 *
 *  Created on: Feb 1, 2015
 *      Author: frank
 */

/**
 * 居然用野蛮方法都能通过，太失望了。
 * 不过可能毕竟是第一道题吧，太难就没人玩了。
 */

#include <iostream>
#include <algorithm> // for std::swap
#include <stdint.h>

using namespace std;

int32_t Steps(int32_t n)
{
	int32_t result = 1;
	while(n > 1)
	{
		n = (n % 2) ? (3*n + 1) : n/2;
		++result;
	}

	return result;
}

int main()
{
	int32_t start, end;
	while(cin>>start>>end) //坑爹：每行2个数字，但是前面的不一定比后面的数字小，要注意！
	{
		int32_t max_steps = 0;
		int32_t start2 = start, end2 = end;
		if(start2 > end2) std::swap(start2, end2);//交换一下
		for(int32_t n = start2; n <= end2; ++n)
		{
			int32_t steps = Steps(n);
			if(steps > max_steps)
			{
				max_steps = steps;
			}
		}
		cout<<start<<" "<<end<<" "<<max_steps<<"\n";
	}
	return 0;
}

