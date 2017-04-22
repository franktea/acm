/*
 * 11332.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: frank
 */
#include <iostream>
#include <stdint.h>
#include <string>
using namespace std;

void Solve(int32_t line)
{
	int32_t result = line;
	while(result >= 10)
	{
		int32_t r = 0;
		while(result >= 10)
		{
			r += result % 10;
			result /= 10;
		}
		r += result;
		result = r;
	}
	cout<<result<<"\n";
}

int main()
{
	int32_t line;
	while(cin>>line)
	{
		if(! line)
			break;

		Solve(line);
	}
	return 0;
}



