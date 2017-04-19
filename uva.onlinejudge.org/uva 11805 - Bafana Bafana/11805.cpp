/*
 * 11805.cpp
 *  uva 11805 - Bafana Bafana
 *  Created on: Apr 19, 2017
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
		int32_t n, k, p;
		cin>>n>>k>>p;
		cout<<"Case "<<i<<": "<<((k+p-1)%n+1)<<"\n";
	}
	return 0;
}



