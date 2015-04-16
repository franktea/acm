/*
 * 294.cpp
 *
 *	title of 294: Divisors
 *
 *  Created on: Feb 1, 2015
 *      Author: frank
 */

#include <iostream>
#include <cmath>
#include <stdint.h>

using namespace std;

int32_t DevisorsOf(const int32_t N)
{
	const int32_t end = sqrt(N);
	int32_t result = 0;
	for(int32_t i = 1; i <= end; ++i)
	{
		if(0 == N % i)
		{
			++result;
		}
	}

	result *= 2;
	if(end*end == N)
		-- result;

	return result;
}

void CheckRange(const int32_t L, const int32_t U)
{
	int32_t max_n = 0;
	int32_t max_devisors = 0;
	for(int32_t n = L; n <= U; ++ n)
	{
		int32_t result = DevisorsOf(n);
		//cout<<"n="<<n<<", devisors="<<result<<endl;
		if(result > max_devisors)
		{
			max_devisors = result;
			max_n = n;
		}
	}

	cout<<"Between "<<L<<" and "<<U<<", "<<max_n<<" has a maximum of "<<
			max_devisors<<" divisors."<<"\n";
}

int main()
{
	int32_t count;
	cin>>count;
	while(count-- > 0)
	{
		int32_t L, U;
		cin>>L>>U;
		CheckRange(L, U);
	}
	return 0;
}

