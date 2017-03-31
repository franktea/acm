/*
 * 755.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: frank
 */

#include <string>
#include <map>
#include <iostream>
#include <cstdlib> // atoi
#include <vector>
#include <cctype> // isdigit

using namespace std;

std::map<char, char> c2n = {{'A','2'}, {'B','2'}, {'C','2'},
		{'D','3'}, {'E','3'}, {'F','3'},
		{'G','4'}, {'H','4'}, {'I','4'},
		{'J','5'}, {'K','5'}, {'L','5'},
		{'M','6'}, {'N','6'}, {'O','6'},
		{'P','7'}, {'R','7'}, {'S','7'},
		{'T','8'}, {'U','8'}, {'V','8'},
		{'W','9'}, {'X','9'}, {'Y','9'}};

void Solve(std::vector<string>& lines)
{
	std::map<string, int> occur_count;
	for(string& line: lines)
	{
		string number = "";
		number.reserve(8);
		for(char c: line)
		{
			if(isdigit(c))
			{
				number.append(1, c);
			}
			else if(isalpha(c))
			{
				number.append(1, c2n[c]);
			}

			if(number.size() == 3)
			{
				number.append("-");
			}
		}

		auto it = occur_count.find(number);
		if(it == occur_count.end())
		{
			occur_count.insert(std::make_pair(number, 1));
		}
		else
		{
			++ it->second;
		}
	}

	int print_lines = 0;
	for(auto it = occur_count.begin(); it != occur_count.end(); ++it)
	{
		if(it->second > 1)
		{
			++ print_lines;
			cout<<it->first<<" "<<it->second<<"\n";
		}
	}

	if(0 == print_lines)
	{
		cout<<"No duplicates.\n";
	}
}

int main()
{
	string line;
	std::getline(cin, line);
	int case_count = atoi(line.c_str());
	for(int i = 0; i < case_count; ++i)
	{
		if(i != 0)
		{
			cout<<"\n";
		}

		std::getline(cin, line); //skip an empty line

		std::getline(cin, line);
		int rows = atoi(line.c_str());
		vector<string> lines;
		lines.reserve(rows);
		for(int r = 0; r < rows; ++r)
		{
			std::getline(cin, line);
			lines.emplace_back(line);
		}
		Solve(lines);
	}
}

