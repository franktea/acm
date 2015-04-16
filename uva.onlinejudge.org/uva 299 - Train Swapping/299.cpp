/*
 * 299.cpp
 *
 *	uva 299 - Train Swapping
 *
 *  Created on: Feb 20, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 看难度是最低的，但是题目实在太长懒得看，搜索题目意思别人说是统计冒泡排序次数。
 */

void BubbleSort(vector<int32_t>& v)
{
	int32_t swap_times = 0;
	for(size_t i = 1; i < v.size(); ++i)
	{
		for(size_t j = 0; j < v.size() - i; ++j)
		{
			if(v[j] > v[j+1])
			{
				std::swap(v[j], v[j+1]);
				++swap_times;
			}
		}
	}

	cout<<"Optimal train swapping takes "<<swap_times<<" swaps.\n";
}

int main()
{
	int32_t total_case;
	cin>>total_case;
	vector<int32_t> v;
	v.reserve(50);
	while(total_case--)
	{
		size_t length;
		cin>>length;
		v.clear();
		int32_t value;
		for(size_t i = 0; i < length; ++i)
		{
			cin>>value;
			v.push_back(value);
		}
		BubbleSort(v);
	}

	return 0;
}
