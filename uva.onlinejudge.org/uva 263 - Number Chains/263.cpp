/*
 * 263.cpp
 *
 *	uva 263 - Number Chains
 *
 *  Created on: Feb 19, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <set>

/**
 * 坑主要是说后来的数字与过去某个数字重复就算结束，而不一定是上一个。
 * 如果只记录上一个，则59994会进入死循环，提交会出现Output limit exceeded
 */

using namespace std;

void get_max_min(int32_t original, int32_t& max_int, int32_t& min_int)
{
	string number = std::to_string(original);
	std::sort(number.begin(), number.end(), std::greater<char>());
	max_int = atoi(number.c_str());
	std::sort(number.begin(), number.end());
	min_int = atoi(number.c_str());
}

int main()
{
	int32_t original;
	while(cin>>original)
	{
		if(0 == original) break;

		cout<<"Original number was "<<original<<"\n";
		std::set<int32_t> last_diffs;
		int32_t steps = 0;
		int32_t max_int = -1, min_int = -1;
		while(1)
		{
			++steps;
			get_max_min(original, max_int, min_int);
			int32_t diff = max_int - min_int;
			cout<<max_int<<" - "<<min_int<<" = "<<diff<<"\n";
			if(last_diffs.find(diff) != last_diffs.end())
				break;

			last_diffs.insert(diff);
			original = diff;
		}
		cout<<"Chain length "<<steps<<"\n\n";
	}
}


