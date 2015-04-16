/*
 * 10037.cpp
 *
 *	uva 10037 - Bridge
 *
 *  Created on: Feb 21, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <sstream>

using namespace std;

/**
 * 小学时候就听说的题目，不过一直没认真解答过。
 * 其实也是用贪心算法，但是关注的数据不止是最大和最小两个，还有第二大的和第二小的。
 */

void Settle(vector<int32_t>& v)
{
	int32_t total = 0;
	std::stringstream ss;
	while(v.size() >= 4)
	{
		int32_t a = v[0];
		int32_t b = v[1];
		int32_t c = v[v.size()-2];
		int32_t d = v[v.size()-1];
		if(2*b < (a+c))
		{
			total += 2*b + a + d;
			ss<<a<<" "<<b<<"\n"<<a<<"\n"<<c<<" "<<d<<"\n"<<b<<"\n";
		}
		else
		{
			total += 2*a + c + d;
			ss<<a<<" "<<d<<"\n"<<a<<"\n"<<a<<" "<<c<<"\n"<<a<<"\n";
		}
		v.resize(v.size()-2); // 最大的两个删掉
	}

	if(v.size() == 3)
	{
		total += v[0] + v[2];
		ss<<v[0]<<" "<<v[2]<<"\n"<<v[0]<<"\n";
		v.resize(2);
	}

	if(v.size() == 2)
	{
		total += v[1];
		ss<<v[0]<<" "<<v[1]<<"\n";
	}
	else // v.size() == 1，就是一开始就只有一个人过河，没其他人
	{
		total += v[0];
		ss<<v[0]<<"\n";
	}

	cout<<total<<"\n";
	cout<<ss.str();
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	vector<int32_t> v;
	v.reserve(1000); // 最大1000
	int32_t case_count;
	cin>>case_count;
	while(case_count --)
	{
		int32_t lines;
		cin>>lines;
		int32_t speed;
		v.clear();
		while(lines--)
		{
			cin>>speed;
			v.push_back(speed);
		}
		std::sort(v.begin(), v.end());
		Settle(v);

		if(case_count > 0) cout<<"\n";
	}
	return 0;
}
