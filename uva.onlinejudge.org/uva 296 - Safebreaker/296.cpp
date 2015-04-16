/*
 * 296.cpp
 *
 *	uva 296 - Safebreaker
 *
 *  Created on: Feb 23, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

// 题目的意思理解错了，差点疯掉。

struct Line
{
	int32_t number;
	int32_t count1;
	int32_t count2;
	string number_str;
};

void ToString(string& str, int32_t number)
{
	str.resize(5); // 仅仅只是四位数
	snprintf(&str[0], str.length(), "%04d", number);
	str.resize(4);
}

bool Check(string& n, vector<Line>& guesses)
{
	for(size_t i = 0; i < guesses.size(); ++i)
	{
		Line& guess = guesses[i];
		int32_t count1 = 0;
		for(int32_t p = 0; p < 4; ++p)
		{
			if(n[p] == guess.number_str[p])
			{
				++count1;
			}
		}

		if(count1 != guess.count1) return false;

		int32_t numbers1[10] = {0};
		int32_t numbers2[10] = {0};
		for(char c: n) ++numbers1[c-'0'];
		for(char c: guess.number_str) ++numbers2[c - '0'];
		int32_t count2 = 0;
		for(size_t index = 0; index < 10; ++index)
		{
			count2 += std::min(numbers1[index], numbers2[index]);
		}
		if(count2 - count1 != guess.count2) return false;
	}
	return true;
}

int main()
{
	int32_t case_count;
	cin>>case_count;
	vector<Line> guesses;
	guesses.reserve(10);
	while(case_count--)
	{
		int32_t lines;
		cin>>lines;
		char c; // 吃掉斜杠
		guesses.clear();
		while(lines--)
		{
			Line line;
			cin>>line.number>>line.count1>>c>>line.count2;
			//cout<<number<<" "<<count1<<" "<<count2<<endl;
			ToString(line.number_str, line.number);
			guesses.push_back(line);
		}

		string strn;
		string result = "";
		for(int32_t n = 0; n <= 9999; ++n)
		{
			ToString(strn, n);
			if(Check(strn, guesses))
			{
				if(result == "")
					result = strn;
				else
				{
					cout<<"indeterminate\n";
					goto end;
				}
			}
		}
		if(result == "")
			cout<<"impossible\n";
		else
			cout<<result<<"\n";

		end: ;
	}
	return 0;
}


