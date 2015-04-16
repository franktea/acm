/*
 * FCTRL2.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <stdint.h>
#include <string>

using namespace std;

vector<string> result;

void Calc(int32_t num)
{

}

int main()
{
	result.resize(101);
	int32_t lines;
	cin>>lines;
	while(lines--)
	{
		int32_t number;
		cin>>number;
		if(result[number] == "")
			Calc(number);
		cout<<result[number]<<"\n";
	}
}


