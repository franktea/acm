/*
 * 136.cpp
 *
 *  Created on: Feb 15, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>

using namespace std;

int main()
{
	int32_t result = 0;
	int32_t current = 2;
	for(int32_t count = 1;; ++current) // 最笨的方法，用这种方法会超时
	{
		int32_t i = current;
		while(i % 2 == 0) i /= 2;
		while(i % 3 == 0) i /= 3;
		while(i % 5 == 0) i /= 5;

		if(i == 1) if(++count >= 1500) break;
	}
	cout<<"The 1500'th ugly number is "<<current<<"."<<"\n";
	return 0;
}
