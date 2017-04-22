/*
 * 11764.cpp
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
		int32_t last;
		cin>>last;
		nums--;
		int32_t up = 0;
		int32_t down = 0;
		while(nums--)
		{
			int32_t current;
			cin>>current;
			if(current > last) up++;
			if(current < last) down++;
			last = current;
		}
		cout<<"Case "<<i<<": "<<up<<" "<<down<<"\n";
	}
	return 0;
}



