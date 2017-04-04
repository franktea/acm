/*
 * 10050.cpp
 *
 *	uva 10050 - Hartals
 *
 *  Created on: Apr 4, 2017
 *      Author: frank
 */

#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

class Strike
{
public:
	Strike(int32_t simulation_days):simulation_days_(simulation_days)
	{
		bit_array_.resize(simulation_days+1, 0); // 第0位不用
	}

	void AddParty(int32_t day)
	{
		int32_t i = 1;
		int32_t current = day;
		while(current <= simulation_days_)
		{
			const int32_t week_day = current % 7;
			if(week_day != 6 && week_day != 0)
			{
				bit_array_[current] = 1;
			}
			current = day * ++i;
		}
	}

	void OutPut()
	{
		int32_t count = 0;
		for(char c: bit_array_)
		{
			count += c;
		}
		cout<<count<<"\n";
	}
private:
	int32_t simulation_days_;
	vector<char> bit_array_; // 听话的孩子没有使用vector<bool>，懒得研究
};

int main()
{
	int32_t case_count;
	cin>>case_count;
	for(int32_t i = 0; i < case_count; ++i)
	{
		int32_t simulation_days;
		cin>>simulation_days;
		Strike s(simulation_days);
		int32_t party_count;
		cin>>party_count;
		for(int32_t l = 0; l < party_count; ++l)
		{
			int32_t day;
			cin>>day;
			s.AddParty(day);
		}
		s.OutPut();
	}
	return 0;
}


