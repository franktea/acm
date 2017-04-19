/*
 * 10055.cpp
 *  uva 10055 - Hashmat the Brave Warrior
 *  Created on: Apr 19, 2017
 *      Author: frank
 */
#include <iostream>
#include <algorithm>
#include <stdint.h>
using namespace std;

int main()
{
	int64_t a, b;
	while(cin>>a>>b)
	{
		if(a < b) swap(a, b);
		cout<<a-b<<"\n";
	}
	return 0;
}



