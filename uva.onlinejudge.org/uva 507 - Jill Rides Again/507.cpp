/*
 * 507.cpp
 *	uva 507 - Jill Rides Again
 *  Created on: Apr 16, 2017
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <stdint.h>
using namespace std;

class ResultStruct
{
public:
	void Check(int32_t index, int32_t value)
	{
		if(current_sum + value >= 0) // 注意这个等于，题目是要找最长的一段，即使等于0的也要算进去
		{
			if(from_index == -1)
			{
				from_index = index;
			}


			to_index = index;

			current_sum += value;
			if(current_sum > max_sum ||
					(current_sum == max_sum && to_index - from_index > max_to_index - max_from_index))
			{
				max_sum = current_sum;
				max_from_index = from_index;
				max_to_index = to_index;
			}
		}
		else
		{
			from_index = -1;
			to_index = -1;
			current_sum = 0;
		}
	}
public:
	int32_t from_index = -1;
	int32_t to_index = -1;
	int32_t current_sum = 0;
public:
	int32_t max_from_index = -1;
	int32_t max_to_index = -1;
	int32_t max_sum = 0;
};

class OneDArray
{
public:
	OneDArray(int32_t case_index, int32_t size):case_index_(case_index)
	{
		v.reserve(size);
		for(int32_t i = 0; i < size; ++i)
		{
			int32_t value;
			cin>>value;
			//cout<<"......."<<value<<endl;
			v.push_back(value);
		}
	}

	void Solve()
	{
		ResultStruct rs;
		for(int32_t i = 0; i < v.size(); ++i)
		{
			rs.Check(i, v[i]);
		}

		if(rs.max_from_index == -1)
		{
			cout<<"Route "<<case_index_<<" has no nice parts\n";
		}
		else
		{
			cout<<"The nicest part of route "<<case_index_<<" is between stops "<<rs.max_from_index+1<<" and "<<rs.max_to_index+2<<"\n";
		}
	}
private:
	const int32_t case_index_;
	vector<int32_t> v;
};

int main()
{
	int32_t case_count;
	cin>>case_count;
	for(int32_t i = 0;i < case_count; ++i)
	{
		int32_t size;
		cin>>size;
		//cout<<"========>"<<size<<endl;
		OneDArray oa(i+1, size-1);
		oa.Solve();
	}
	return 0;
}



