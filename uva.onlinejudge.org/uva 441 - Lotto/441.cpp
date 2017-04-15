/*
 * 451.cpp
 *  uva 441 - Lotto
 *  Created on: Apr 15, 2017
 *      Author: frank
 */
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <vector>
using namespace std;

class SixSelector
{
public:
	SixSelector(int32_t count)
	{
		this->count = count;
		v.reserve(count);
	}

	void Input()
	{
		int32_t number;
		for(int32_t i = 0; i < count; ++i)
		{
			cin>>number;
			v.push_back(number);
		}
		sort(v.begin(), v.end());
	}

	void OutPut()
	{
		for(int32_t i1 = 0; i1 < count; ++i1)
			for(int32_t i2 = i1 + 1; i2 < count; ++i2)
				for(int32_t i3 = i2 + 1; i3 < count; ++i3)
					for(int32_t i4 = i3 + 1; i4 < count; ++i4)
						for(int32_t i5 = i4 + 1; i5 < count; ++i5)
							for(int32_t i6 = i5 + 1; i6 < count; ++i6)
							{
								cout<<v[i1]<<" "<<v[i2]<<" "<<v[i3]<<" "<<
										v[i4]<<" "<<v[i5]<<" "<<v[i6]<<"\n";
							}
	}
private:
	int32_t count;
	vector<int32_t> v;
};

int main()
{
	int32_t count;
	int32_t case_count = 0;
	cin>>count;
	while(0 != count)
	{
		if(case_count != 0) cout<<"\n";

		SixSelector ss(count);
		ss.Input();
		ss.OutPut();

		++case_count;
		cin>>count;
	}
}



