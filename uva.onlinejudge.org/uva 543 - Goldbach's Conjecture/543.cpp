/*
 * 543.cpp
 *
 *  Created on: Jan 10, 2016
 *      Author: frank
 */
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

bool IsPrime(int p)
{
    if(p == 2) return true;
    if(p % 2 == 0) return false;
    int max_n = sqrt(p);
    for(int i = 3; i <= max_n; i+=2)
    {
        if(p % i == 0)
            return false;
    }

    return true;
}

void Generate(std::set<int>& primes)
{
    //primes.insert(2);
    primes.insert(3);
    const int max_n = 1000001/6;
    for(int i = 1; i < max_n; ++i)
    {
        const int a = 6*i-1;
        if(IsPrime(a))
            primes.insert(a);
        const int b = 6*i+1;
        if(IsPrime(b))
            primes.insert(b);
    }
}

void Check(int number, const set<int>& primes)
{
    for(int i = 3; i <= number/2; i+=2)
    {
        if(primes.find(i) != primes.end()
           && primes.find(number-i) != primes.end())
        {
            cout<<number<<" = "<<i<<" + "<<number-i<<endl;
            return;
        }
    }
    cout<<"Goldbach's conjecture is wrong."<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::set<int> primes;
    Generate(primes);
    int number;
    while(cin>>number && number)
    {
        Check(number, primes);
    }

    return 0;
}





