/*
 * 11875.cpp
 *  uva 11875 - Brick Game
 *  Created on: Apr 19, 2017
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <stdint.h>
using namespace std;

int main()
{
	int32_t cnt;
	cin>>cnt;
	vector<int32_t> v;
	v.reserve(11);
	for(int32_t i = 1; i <= cnt; ++i)
	{
		v.clear();
		int32_t s;
		cin>>s;
		for(int32_t j = 0; j < s; ++j)
		{
			int32_t num;
			cin>>num;
			v.push_back(num);
		}
		cout<<"Case "<<i<<": "<<v[s/2]<<"\n";
	}
	return 0;
}



