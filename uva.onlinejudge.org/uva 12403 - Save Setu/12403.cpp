/*
 * 12403.cpp
 *
 *  Created on: Apr 21, 2017
 *      Author: frank
 */
#include <iostream>
#include <string>
#include <sstream>
#include <stdint.h>
using namespace std;

int main()
{
	int32_t cnt;
	cin>>cnt;
	int32_t result = 0;
	while(cnt--)
	{
		string word;
		cin>>word;
		if(word == "donate")
		{
			int32_t num;
			cin>>num;
			result += num;
		}
		else
		{
			cout<<result<<"\n";
		}
	}
	return 0;
}



