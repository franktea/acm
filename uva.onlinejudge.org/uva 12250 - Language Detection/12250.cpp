/*
 * 12250.cpp
 *	uva 12250 - Language Detection
 *  Created on: Apr 15, 2017
 *      Author: frank
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	std::map<string, string> lm = {{"HELLO", "ENGLISH"},
			{"HOLA", "SPANISH"}, {"HALLO", "GERMAN"},
			{"BONJOUR", "FRENCH"}, {"CIAO", "ITALIAN"},
			{"ZDRAVSTVUJTE", "RUSSIAN"}};

	string line;
	int32_t index = 0;
	while(cin>>line)
	{
		if(line[0] == '#')
			break;

		auto it = lm.find(line);
		if(it == lm.end())
		{
			cout<<"Case "<<++index<<": UNKNOWN\n";
		}
		else
		{
			cout<<"Case "<<++index<<": "<<it->second<<"\n";
		}
	}
}



