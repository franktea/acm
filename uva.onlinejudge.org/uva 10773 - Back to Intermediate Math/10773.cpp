/*
 * 10773.cpp
 *  uva 10773 - Back to Intermediate Math
 *  Created on: Apr 19, 2017
 *      Author: frank
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdint.h>
using namespace std;

void Solve(int32_t no, double d, double u, double v)
{
	cout<<"Case "<<no<<": ";
	if(u == 0 || v == 0 || v <= u)
	{
		cout<<"can't determine\n";
		return;
	}
	double v2 = sqrt(v*v - u*u);
	double result = d / v2 - d/v;
	cout<<fixed<<std::setprecision(3)<<result<<"\n";
}

int main()
{
	int32_t cnt;
	cin>>cnt;
	for(int32_t i = 1; i <= cnt; ++i)
	{
		double d, u, v;
		cin>>d>>u>>v;
		Solve(i, d, u, v);
	}
	return 0;
}



