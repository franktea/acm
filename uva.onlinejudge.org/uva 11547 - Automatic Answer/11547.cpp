/*
 * 11547.cpp
 *
 *  Created on: Apr 21, 2017
 *      Author: frank
 */
#include <iostream>
#include <cmath>
#include <stdint.h>
using namespace std;

int main()
{
	int32_t cnt;
	cin>>cnt;
	while(cnt--)
	{
		int64_t num;
		cin>>num;
		cout<<abs(((num*567/9+7492)*235/47-498)/10%10)<<"\n";
	}
	return 0;
}



