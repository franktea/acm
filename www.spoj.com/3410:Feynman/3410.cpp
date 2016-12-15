/*
 * 3410.cpp
 *
 *  Created on: Dec 15, 2016
 *      Author: frankt
 */

#include <iostream>
#include <stdint.h>

using namespace std;

int main()
{
    int arr[101];
    arr[0] = 0;
    for(int32_t i = 1; i < 101; ++i)
    {
        arr[i] = i*i + arr[i-1];
    }
    int32_t number;
    cin>>number;
    while(number)
    {
        cout<<arr[number]<<"\n";
        cin>>number;
    }
}


