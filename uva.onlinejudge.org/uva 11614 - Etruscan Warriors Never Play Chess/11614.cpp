/*
 * 11614.cpp
 *  uva 11614 - Etruscan Warriors Never Play Chess
 *  Created on: Apr 19, 2017
 *      Author: frank
 */
#include <cmath>
#include <iostream>
#include <stdint.h>
using namespace std;

// n=k(k+1)/2 => k = (sqrt(8*n+1)-1)/2

void Solve(int64_t n)
{
	int64_t k = (sqrt(8.0*n+1)-1.0)/2.0;
	cout<<k<<"\n";
}

int main()
{
	int32_t cnt;
	cin>>cnt;
	while(cnt--)
	{
		int64_t n;
		cin>>n;
		Solve(n);
	}
	return 0;
}

