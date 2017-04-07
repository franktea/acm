/*
 * 1586.cpp
 *
 *	uva 1586 - Molar mass
 *
 *  Created on: Apr 8, 2017
 *      Author: frank
 */

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <iomanip>

using namespace std;

std::map<char, double> weight_map = {{'C',12.01}, {'H',1.008}, {'O',16.00}, {'N',14.01}};

void Solve(const string& line)
{
	double total = 0;
	double last = 0;
	int number = 0;
	for(char c:line)
	{
		if(isdigit(c))
		{
			number = number*10 + (c-'0');
		}
		else
		{
			number = !number ? 1 : number;
			total += last*number;
			last = weight_map[c];
			number = 0;
		}
	}
	number = !number ? 1 : number;
	total += last*number;
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<total<<"\n";
}

int main()
{
	int lines;
	cin>>lines;
	string line;
	while(lines--)
	{
		cin>>line;
		Solve(line);
	}
	return 0;
}


