/*
 * 113.cpp
 *
 *	uva 113 - Power of Cryptography
 *
 *  Created on: Feb 17, 2015
 *      Author: frank
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdint.h>

using namespace std;

// 有很大的整数，甚至超过了int64，但是用double可以幸运地通过

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
    double n, p;

    while (cin>>n>>p) {
        cout<<int32_t(0.5 + pow(p, 1/n))<<"\n";
    }

    return 0;
}


