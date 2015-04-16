/*
 * 272.cpp
 *
 * uva 272 - TEX Quotes
 *
 *  Created on: Feb 23, 2015
 *      Author: frank
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	bool even = true;
	while(std::getline(cin, line))
	{
		for(char c: line)
		{
			if(c=='"')
			{
				even = !even;
				// 对于c++的cout，改成三目运算符提交发现也没有比下面的if..else快多少
				const char* tmp = even ? "''" : "``";
				cout<<tmp;
//				if(even) cout<<"''";
//				else cout<<"``";
			}
			else
				cout<<c;
		}
		cout<<"\n";
	}
	return 0;
}


