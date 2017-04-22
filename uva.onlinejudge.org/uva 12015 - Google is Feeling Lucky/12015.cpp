/*
 * 12015.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <stdint.h>
#include <string>
using namespace std;

int main()
{
	int32_t cnt;
	cin>>cnt;
	for(int32_t i = 1; i <= cnt; ++i)
	{
		cout<<"Case #"<<i<<":\n";
		int32_t max_value;
		vector<string> strs;
		for(int32_t i = 0; i < 10; ++i)
		{
			string str;
			cin>>str;
			int32_t v;
			cin>>v;
			if(strs.empty() || v > max_value)
			{
				max_value = v;
				strs.clear();
				strs.push_back(str);
			}
			else if(v == max_value)
			{
				strs.push_back(str);
			}
		}
		for(auto& str: strs)
			cout<<str<<"\n";
	}
	return 0;
}



