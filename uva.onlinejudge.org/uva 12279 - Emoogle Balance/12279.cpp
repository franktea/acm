/*
 * 12279.cpp
 *	uva 12279 - Emoogle Balance
 *  Created on: Apr 15, 2017
 *      Author: frank
 */
#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
	int32_t count;
	cin>>count;
	int32_t index = 0;
	while(0 != count)
	{
		int32_t sum = 0;
		int32_t number;
		for(int32_t i = 0; i < count; ++i)
		{
			cin>>number;
			if(number == 0) --sum;
			else ++sum;
		}
		cout<<"Case "<<++index<<": "<<sum<<"\n";
		cin>>count;
	}
	return 0;
}



