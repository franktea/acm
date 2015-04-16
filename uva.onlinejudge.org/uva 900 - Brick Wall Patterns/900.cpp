/*
 * 900.cpp
 *
 *	uva 900 Brick Wall Patterns
 *
 *  Created on: Feb 20, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>

using namespace std;

const int32_t MAX_WALL_LENGTH = 51;

/**
 * f(1) = 1; f(2) = 2; f(3) = 3; f(4) = 5; f(5) = 8; f(6) = 13
 * 可见，f(n) = f(n-2) + f(n-2)，就是一个斐波拉契数列。
 *
 * 本题最大不超过50，所以直接计算，无须用数列的通式。
 */

int main()
{
	int32_t wall[MAX_WALL_LENGTH];
	wall[1] = 1;
	wall[2] = 2;
	for(int32_t i = 3; i <= 50; ++i)
	{
		wall[i] = wall[i-1] + wall[i-2];
	}

	int32_t length;
	while(cin>>length)
	{
		if(0 == length) break;
		cout<<wall[length]<<"\n";
	}

	return 0;
}

