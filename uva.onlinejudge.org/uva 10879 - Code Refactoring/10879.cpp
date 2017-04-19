/*
 * 10879.cpp
 *	uva 10879 - Code Refactoring
 *  Created on: Apr 19, 2017
 *      Author: frank
 */
#include <iostream>
#include <set>
#include <algorithm>
#include <stdint.h>
using namespace std;

void Solve(int32_t no, int32_t num)
{
	set<std::pair<int32_t, int32_t>> results;
	for(int32_t i = 2; i <= num/2; ++i)
	{
		if(num % i == 0)
		{
			int32_t b = num / i;
			int32_t a = i;
			if(a > b)
				std::swap(a, b);
			if(a != b)
				results.insert(std::pair<int32_t, int32_t>{a, b});
			if(results.size() == 2)
			{
				int32_t a, b, c, d;
				auto it = results.begin();
				a = it->first;
				b = it->second;
				++it;
				c = it->first;
				d = it->second;
				cout<<"Case #"<<no<<": "<<num<<" = "<<a<<" * "<<b<<" = "<<c<<" * "<<d<<"\n";
				return;
			}
		}
	}
}

int main()
{
	int32_t case_count;
	cin>>case_count;
	for(int32_t i = 1; i <= case_count; ++i)
	{
		int32_t num;
		cin>>num;
		Solve(i, num);
	}
	return 0;
}



