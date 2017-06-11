/*
 * 12468.cpp
 *
 *  Created on: Jun 11, 2017
 *      Author: frank
 */
#include <iostream>
#include <stdint.h>
#include <algorithm>

using namespace std;

int main()
{
	int32_t a, b;
	cin>>a>>b;
	while(a != -1 && b != -1)
	{
		int32_t up_times = b >= a ? b - a : b + 100 - a;
		int32_t down_times = b >= a ? a + 100 - b : a - b;
		cout<<std::min(up_times, down_times)<<"\n";

		cin>>a>>b;
	}
	return 0;
}



