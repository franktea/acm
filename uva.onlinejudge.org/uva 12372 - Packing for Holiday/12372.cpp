/*
 * 12372.cpp
 *
 *  Created on: Apr 21, 2017
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
		int32_t a, b, c;
		cin>>a>>b>>c;
		cout<<"Case "<<i<<": ";
		if(a<=20 && b<=20 && c<=20)
			cout<<"good\n";
		else
			cout<<"bad\n";
	}
	return 0;
}



