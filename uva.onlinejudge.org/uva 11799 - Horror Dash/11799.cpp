/*
 * 11799.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: frank
 */
#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
	int32_t cnt;
	cin>>cnt;
	for(int32_t i = 1; i <= cnt; ++i)
	{
		int32_t nums;
		cin>>nums;
		int32_t max = 0;
		while(nums--)
		{
			int32_t value;
			cin>>value;
			if(value > max) max = value;
		}
		cout<<"Case "<<i<<": "<<max<<"\n";
	}
	return 0;
}



