/*
 * 11942.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: frank
 */
#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
	cout<<"Lumberjacks:\n";
	int32_t cnt;
	cin>>cnt;
	while(cnt--)
	{
		bool desc = false;
		bool asc = false;
		int32_t last;
		cin>>last;
		//cout<<"last:"<<last<<"\n";
		for(int32_t i = 1; i <= 9; ++i)
		{
			int32_t cur;
			cin>>cur;
			//cout<<"cur:"<<cur<<"\n";
			if(cur > last)
				asc = true;
			if(cur < last)
				desc = true;
			if(desc && asc)
			{
				while(++i <= 9)
					cin>>cur;
				break;
			}
			last = cur;
		}
		if(desc && asc)
			cout<<"Unordered\n";
		else
			cout<<"Ordered\n";
	}
	return 0;
}



