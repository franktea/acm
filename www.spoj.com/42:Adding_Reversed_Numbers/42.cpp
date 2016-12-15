/*
 * 42.cpp
 *
 *  Created on: Dec 15, 2016
 *      Author: frankt
 */

#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

uint32_t Reverse(uint32_t number)
{
    uint32_t result = 0;
    while(number)
    {
        result = result*10 + number%10;
        number /= 10;
    }
    return result;
}

int main()
{
    int32_t case_count;
    cin>>case_count;
    while(case_count--)
    {
        uint32_t a;
        uint32_t b;
        cin>>a>>b;
        cout<<Reverse(Reverse(a) + Reverse(b))<<"\n";
    }
    return 0;
}


