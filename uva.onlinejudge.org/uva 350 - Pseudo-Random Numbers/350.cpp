/*
 * 350.cpp
 *
 *	uva 350 - Pseudo-Random Numbers
 *
 *  Created on: Feb 27, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <map>

using namespace std;

typedef int32_t data_type; // 如果int32越界，可以在这里改

void Solve(data_type Z, data_type I, data_type M, data_type L)
{
	std::map<data_type, data_type> index = {{L, 1}};
	data_type i = 1;
	while(1)
	{
		++i;
		L = (Z*L + I) % M;
		auto it = index.find(L);
		if(index.end() != it)
		{
			data_type path_len = i - it->second;
			cout<<path_len<<"\n";
			return;
		}
		index.insert({L, i});
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	data_type Z, I, M, L;
	int32_t case_count = 0;
	while(cin>>Z>>I>>M>>L)
	{
		if(0 == Z && 0 == I && 0 == M && 0 == L) break;
		cout<<"Case "<<++case_count<<": ";
		Solve(Z, I, M, L);
	}
	return 0;
}


