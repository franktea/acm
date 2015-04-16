/*
 * test.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>

using namespace std;

int main()
{
	int32_t num;
	while(cin>>num)
	{
		if(num == 42) break;
		cout<<num<<"\n";
	}
	return 0;
}


