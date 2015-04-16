/*
 * 458.cpp
 *
 *	uva 458 - The Decoder
 *
 *  Created on: Mar 14, 2015
 *      Author: frank
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	while(std::getline(cin, line))
	{
		for(char& c: line)
		{
			c -= 7;
		}
		cout<<line<<"\n";
	}
	return 0;
}


