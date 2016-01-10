/*
 * 10110.cpp
 *
 *  uva 10110 - Light, more light
 *
 *  Created on: Jan 10, 2016
 *      Author: frank
 */

// 参考这里：
// http://programming-study-notes.blogspot.co.id/2014/02/uva-10110-light-more-light.html

#include <cmath>
#include <stdint.h>
#include <iostream>

using namespace std;



int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	uint32_t number;
	while(cin>>number && number)
	{
		uint32_t t = sqrt(number);
		if(t * t == number)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	return 0;
}


