/*
 * 256.cpp
 *
 *	uva 256 - Quirksome Squares
 *
 *  Created on: Feb 23, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip> // std::setfill, std::setw
#include <stdint.h>

using namespace std;

std::string ToString(int32_t number, int32_t width)
{
	std::stringstream ss;
	ss<<setfill('0')<<setw(width)<<number;
	return ss.str();
}

int main()
{
	vector<string> lines {9, ""};
	for(int32_t i = 2; i <= 8; i+=2)
	{
		lines[i].reserve(512);
		const int32_t max_number = pow(10, i);
		const int32_t half = pow(10, i/2);
		for(int32_t number = 0; number < max_number; ++ number)
		{
			const int32_t a = number / half;
			const int32_t b = number % half;
			if( (a+b)*(a+b) == number)
			{
				lines[i].append(ToString(number, i));
				lines[i].append("\n");
			}
		}
	}

	int32_t n;
	while(cin>>n)
	{
		cout<<lines[n];
	}

	return 0;
}


