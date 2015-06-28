/*
 * 10038.cpp
 *
 *	uva 10038 - Jolly Jumpers
 *
 *  Created on: Jun 28, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <bitset>

using namespace std;

class JollyChecker
{
public:
	JollyChecker(int32_t count): bits_(0), count_(count) {}
public:
	void Read()
	{
		int32_t number_1;
		cin>>number_1;
		bool ended = false;
		for(int32_t i = 1; i < count_; ++i)
		{
			int32_t number_2;
			cin>>number_2;
			if(ended)
			{
				continue;
			}

			int32_t delta = number_2 > number_1 ? number_2 - number_1 : number_1 - number_2; // 懒得用abs
			if(delta < 1 || delta > count_ - 1 || bits_.test(delta))
			{
				ended = true;
				cout<<"Not jolly\n";
				continue;
			}
			bits_.set(delta);
			number_1 = number_2;
		}
		if(!ended)
		{
			cout<<"Jolly\n";
		}
	}
private:
	bitset<3000> bits_;
	const int32_t count_;
};

int main()
{
	cout.sync_with_stdio(false);
	cin.sync_with_stdio(false);
	int32_t count;
	while(cin>>count)
	{
		JollyChecker jc(count);
		jc.Read();
	}
	return 0;
}

