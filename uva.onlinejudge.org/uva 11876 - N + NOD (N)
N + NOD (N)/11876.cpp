/*
 * uva 11876 - N + NOD (N)
 *
 *  Created on: Apr 22, 2018
 *      Author: frank
 */
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

std::vector<int> sequence = {1, 2};

int CountOfDevisors(int value)
{
	int result = 0;
	int v = sqrt(value);
	for(int i = 1; i <= v; ++i)
	{
		if(value % i == 0)
		{
			if(i * i == value)
			{
				result += 1;
			}
			else
			{
				result += 2;
			}
		}
	}
	return result;
}

void InitSequence()
{
	int current = 2;
	while(current < 1000000)
	{
		current = current + CountOfDevisors(current);
		sequence.push_back(current);
	}
}

int main()
{
	InitSequence();
//	for(auto v: sequence)
//	{
//		cout<<v<<"\n";
//	}
	int cases;
	cin>>cases;
	for(int i = 1; i <= cases; ++i)
	{
		cout<<"Case "<<i<<": ";
		int a, b;
		cin>>a>>b;
		auto it1 = std::lower_bound(sequence.begin(), sequence.end(), a);
		auto it2 = std::upper_bound(sequence.begin(), sequence.end(), b);
		cout<<it2 - it1;
		cout<<"\n";
	}
	return 0;
}



