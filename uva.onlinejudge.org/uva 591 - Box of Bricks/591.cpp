/*
 * 591.cpp
 *
 *	uva 591 - Box of Bricks
 *
 *  Created on: Mar 14, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	vector<int32_t> bricks;
	bricks.reserve(50);
	int32_t stacks;
	int32_t case_count = 0;
	while(cin>>stacks)
	{
		if(0 == stacks) break;
		cout<<"Set #"<<++case_count<<"\n";
		int32_t sum = 0;
		bricks.clear();
		for(int32_t i = 0; i < stacks; ++i)
		{
			int32_t brick_count;
			cin>>brick_count;
			bricks.push_back(brick_count);
			sum += brick_count;
		}
		const int32_t average = sum/stacks;
		int32_t result = 0;
		for(int32_t c: bricks)
		{
			result += (c > average ? c - average : 0);
		}
		cout<<"The minimum number of moves is "<<result<<".\n\n";
	}
	return 0;
}

