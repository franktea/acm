/*
 * 382.cpp
 *
 *  uva 382 Perfection
 *
 *  Created on: Feb 27, 2015
 *      Author: frank
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdint.h>

using namespace std;

/**
 * 简单不代表没坑。此题的坑：对于数字1的判断要注意，
 * 然后就是每行输出有2个空格，而不是一个空格。
 */

void Solve(const int32_t number)
{
	if(number == 1)
	{
		cout<<setw(5)<<number<<"  DEFICIENT\n";
		return;
	}

    const int32_t last = sqrt(number);
    int32_t sum = 1;
    for(int32_t i = 2; i <= last; ++i)
    {
        if(number % i == 0)
        {
            sum += i;
            if(i != last || (i == last && i*i != number))
            {
                sum += number / i;
            }
        }
    }

    if(sum == number) cout<<setw(5)<<number<<"  PERFECT\n";
    else if(sum > number) cout<<setw(5)<<number<<"  ABUNDANT\n";
    else cout<<setw(5)<<number<<"  DEFICIENT\n";
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
    cout<<"PERFECTION OUTPUT\n";
    int32_t number;
    while(cin>>number)
    {
        if(0 == number) break;
        Solve(number);
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}

