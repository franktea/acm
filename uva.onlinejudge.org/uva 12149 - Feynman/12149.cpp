/*
 * 12149.cpp
 *
 *  Created on: Apr 19, 2017
 *      Author: frank
 */
#include <iostream>
#include <stdint.h>
using namespace std;
// 1*1 + 2*2 +....+n*n, 平方和公式=N(N+1)(2N+1)/6

int main()
{
	int32_t n;
	while(cin>>n)
	{
		if(! n) break;
		cout<<n*(n+1)*(2*n+1)/6<<"\n";
	}
	return 0;
}



