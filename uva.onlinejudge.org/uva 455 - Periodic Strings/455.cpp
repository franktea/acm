/*
 * 455.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: frank
 */

#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

size_t FindNext(size_t last_index, const string& line)
{
	for(size_t i = last_index + 1; i <= line.size()/2; ++i)
	{
		//cout<<"|||||||||||||||||"<<i<<"\n";
		if(line[0] == line[i] && line.size() % i == 0)
			return i;
	}

	return line.size();
}

bool Check(size_t index, const string& line)
{
	size_t i = 1;
	while(i * index < line.size())
	{
		for(size_t n = 0; n < index; ++n)
		{
			if(line[n] != line[i*index+n])
				return false;
		}

		++i;
	}

	return true;
}

void Solve(const string& line)
{
	size_t last_index = 0;
	bool found = false;
	while(!found && last_index <= line.size()/2)
	{
		//cout<<":::::"<<last_index<<"\n";
		last_index = FindNext(last_index, line);
		found = Check(last_index, line);
		if(found)
		{
			cout<<last_index<<"\n";
			return;
		}
	}

	cout<<line.size()<<"\n";
}

int main()
{
	int32_t count;
	cin>>count;
	string line;
	for(int32_t i = 0; i < count; ++i)
	{
		if(i > 0)
		{
			cout<<"\n";
		}

		cin>>line;
		//cout<<"=====>"<<line<<"\n";
		Solve(line);
	}
}

