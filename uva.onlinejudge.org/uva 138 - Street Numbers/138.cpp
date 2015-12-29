/*
 * 138.cpp
 *
 *  Created on: Dec 30, 2015
 *      Author: frank
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdint.h>

using namespace std;

// n*(n+1)/2 = x^2, 1 < x < n



int main()
{
	int64_t found_count = 0;
	int64_t n = 2;
	while(found_count < 10)
	{
		++n;
		const int64_t lh = n*(n+1)/2;
		int64_t x = sqrt(lh);
		if(x*x == lh)
		{
			++ found_count;
			cout<<std::right<<std::setw(10)<<x
					<<std::right<<std::setw(10)<<n<<endl;
		}
	}
	return 0;
}



