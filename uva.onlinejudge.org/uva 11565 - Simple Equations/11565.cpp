/*
 * 11565.cpp
 *  uva 11565 - Simple Equations
 *  Created on: Apr 15, 2017
 *      Author: frank
 */

#include <iostream>
#include <cmath>
#include <stdint.h>
using namespace std;

void Solve(int32_t A, int32_t B, int32_t C)
{
	int32_t max_possible = sqrt(C);
	for(int32_t x = -max_possible; x <= max_possible; ++x)
		for(int32_t y = x+1; y <= 100; ++y)
			for(int32_t z = y+1; z <= 100; ++z)
			{
				if(x + y + z != A) continue;
				if(x*y*z != B) continue;
				if(x*x + y*y +z*z != C) continue;
				cout<<x<<" "<<y<<" "<<z<<"\n";
				return;
			}
	cout<<"No solution.\n";
}

int main()
{
	int32_t count;
	cin>>count;
	while(count--)
	{
		int32_t A, B, C;
		cin>>A>>B>>C;
		Solve(A, B, C);
	}

	return 0;
}



