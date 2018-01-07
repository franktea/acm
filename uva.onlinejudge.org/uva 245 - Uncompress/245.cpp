/*
 * 245.cpp
 *  uva 245 - Uncompress
 *  Created on: Jan 6, 2018
 *      Author: frank
 */
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
	std::vector<string> words;
	std::string line;
	while(std::getline(cin, line))
	{
		if(line == "")
		{
			cout<<"\n";
			continue;
		}

		if(line == "0")
			break;

		enum status { WORD, NUMBER, OTHER};
		status s = OTHER;
		string current = "";

		auto check_word = [&](){
			if(s == WORD)
			{
				words.push_back(current);
				cout<<current;
				current = "";
			}
			else if(s == NUMBER)
			{
				int value = std::stoi(current);
//				cout<<"[=======>|"<<value<<"|";
//				for(auto& word: words)
//				{
//					cout<<word<<"|";
//				}
//				cout<<"]";
				current = "";
				cout<<words[words.size() - value];
				string w = words[words.size() - value];
				words.erase(words.begin() + words.size() - value);
				words.push_back(w);
			}
		};

		for(char c: line)
		{
			if(std::isalpha(c))
			{
				s = 	WORD;
				current.push_back(c);
			}
			else if(std::isdigit(c))
			{
				s = NUMBER;
				current.push_back(c);
			}
			else
			{
				if(current != "")
				{
					check_word();
				}
				s = OTHER;
				current = "";
				cout<<c;
			}
		}

		check_word();

		cout<<"\n";
	}
}



