/*
 * 11723.cpp
 *  uva 11723 - Numbering Roads
 *  Created on: Apr 19, 2017
 *      Author: frank
 */
#include <iostream>
#include <stdint.h>
using namespace std;

void Solve(int32_t no, int32_t R, int32_t N)
{
	cout<<"Case "<<no<<": ";
	int32_t result = R / N;
	if(R % N) result += 1;
	result -= 1;
	if(result <= 26)
		cout<<result<<"\n";
	else
		cout<<"impossible\n";
}

int main()
{
	int32_t cnt;
	int32_t R, N;
	while(cin>>R>>N)
	{
		if(!R && !N)
			break;
		Solve(++cnt, R, N);
	}
}



