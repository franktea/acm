/*
 * 10684.cpp
 *  uva 10684 - The jackpot
 *  just 1d max range sum problem
 *  Created on: Apr 18, 2017
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

using namespace std;

class MaxRange
{
public:
	MaxRange(int32_t ct)
	{
		v.reserve(ct);
	}

	void Add(int32_t value)
	{
		v.push_back(value);
	}

	int32_t Solve()
	{
		int32_t result = 0;
		int32_t current_max = max(v[0], 0);
		for(size_t i = 1; i < v.size(); ++i)
		{
			if(current_max + v[i] > 0)
			{
				current_max += v[i];
			}
			else
			{
				current_max = max(v[i], 0);
			}

			if(current_max > result)
				result = current_max;
		}

		return result;
	}
private:
	vector<int32_t> v;
};

int main()
{
	int32_t cnt;
	cin>>cnt;
	while(0 != cnt)
	{
		MaxRange mr(cnt);
		while(cnt--)
		{
			int32_t value;
			cin>>value;
			mr.Add(value);
		}
		int32_t result = mr.Solve();
		if(result > 0)
			cout<<"The maximum winning streak is "<<result<<".\n";
		else
			cout<<"Losing streak.\n";
		cin>>cnt;
	}
	return 0;
}



