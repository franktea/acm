/*
 * 343.cpp
 *
 *	uva 343 - What Base Is This?
 *
 *  Created on: Feb 28, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdint.h>
#include <cassert>

using namespace std;

// 主要的坑：最小的base是2，所以就算对于数字0和1base也要显示成2

class SInt
{
public:
	explicit SInt(string& str): str_(str)
	{
		int32_t max_number = 0;
		for(char c: str_)
		{
			max_number = std::max(max_number, ToInt(c));
		}
		min_base_ = ++max_number;
		if(min_base_ < 2) min_base_ = 2; // 最小必须是2，1不算
	}

	int32_t AsBase(int32_t base) // 对应base的值
	{
		int32_t result = 0;
		int32_t b = 1;
		for(int32_t i = str_.size() - 1; i >= 0; --i)
		{
			result += ToInt(str_[i])*b;
			b*=base;
		}
		return result;
	}

	int32_t MinBase() { return min_base_; }
private:
	int32_t ToInt(char c)
	{
		return (c >= '0' && c <= '9') ? c-'0' : c-'A'+10;
	}
private:
	std::string& str_;
	int32_t min_base_;
};

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	string string1, string2;
	while(cin>>string1>>string2)
	{
		SInt x(string1);
		SInt y(string2);
		bool found = false;
		for(int32_t base1 = x.MinBase(); base1 <= 36; ++base1)
		{
			for(int32_t base2 = y.MinBase(); base2 <= 36; ++base2)
			{
				if(x.AsBase(base1) == y.AsBase(base2))
				{
					cout<<string1<<" (base "<<base1<<") = "<<string2<<" (base "<<base2<<")\n";
					found = true;
					break;
				}
			}
			if(found) break;
		}
		if(!found) cout<<string1<<" is not equal to "<<string2<<" in any base 2..36\n";
	}
	return 0;
}
