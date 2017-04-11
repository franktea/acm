/*
 * 673.cpp
 *
 *  Created on: Apr 11, 2017
 *      Author: frank
 */

#include <iostream>
#include <stack>
#include <string>
#include <stdint.h>

using namespace std;

bool Solve(const string& str)
{
	stack<char> s;
	for(char c: str)
	{
		switch(c)
		{
		case '(':
		case '[':
			s.push(c);
			break;
		case ')':
			if(s.empty()) return false;
			if(s.top() != '(') return false;
			s.pop();
			break;
		case ']':
			if(s.empty()) return false;
			if(s.top() != '[') return false;
			s.pop();
			break;
		}
	}
	return s.empty();
}

int main()
{
	string line;
	std::getline(cin, line);
	int32_t cs = atoi(line.c_str());
	while(cs--)
	{
		std::getline(cin, line); // 注意有空行，用getline不要用cin
		if(Solve(line))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}



