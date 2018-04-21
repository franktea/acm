/*
 * uva 444 - Encoder and Decoder
 *
 *  Created on: Apr 21, 2018
 *      Author: frank
 */
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

std::map<int, char> num_map;

string ToNumber(const string& line)
{
	string result;
	for(size_t i = 0; i < line.size(); ++i)
	{
		int c = line[i];
		result.append(std::to_string(c));
	}
	std::reverse(result.begin(), result.end());
	return result;
}

string ToString(const string& line)
{
	string str = line;
	std::reverse(str.begin(), str.end());
	string result;
	int current_num = 0;
	for(char c: str)
	{
		int num = c - '0';
		current_num = current_num*10 + num;
		auto it = num_map.find(current_num);
		if(it != num_map.end())
		{
			result.push_back(it->second);
			current_num = 0;
		}
	}
	return result;
}

int main()
{
	for(char c = 'A'; c <= 'Z'; ++c)
	{
		int num = c;
		num_map.insert(std::make_pair(num, c));
	}

	for(char c = 'a'; c <= 'z'; ++c)
	{
		int num = c;
		num_map.insert(std::make_pair(num, c));
	}

	char others[] = {' ', '!', ',', '.', ':', ';', '?'};
	for(char c: others)
	{
		int num = c;
		num_map.insert(std::make_pair(num, c));
	}

	string line;
	while(std::getline(cin, line))
	{
		if(line.empty())
		{
			cout<<"\n";
			continue;
		}

		if(line[0] >= '0' && line[0] <= '9')
		{
			cout<<ToString(line)<<"\n";
		}
		else
		{
			cout<<ToNumber(line)<<"\n";
		}
	}
	return 0;
}



