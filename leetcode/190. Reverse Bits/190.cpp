/*
 * 190.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

// 用了bitset，小心用法

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bs(n);
        for(size_t index = 0; index < 16; ++index)
        {
            bool tmp = bs[31-index];
            bs[31-index] = bs[index];
            bs.set(index, tmp);
        }
        return bs.to_ulong();
    }
};

int main()
{
	uint32_t n = 43261596;

	Solution* ps = new Solution;
	cout<<ps->reverseBits(n)<<"\n";

//	cout<<bitset<32>(n).to_string()<<"\n";
//	cout<<bitset<8>(n%256).to_string()<<"\n";
//	n /= 256;
//	cout<<bitset<8>(n%256).to_string()<<"\n";
//	n /=256;
//	cout<<bitset<8>(n%256).to_string()<<"\n";
//	n /= 256;
//	cout<<bitset<8>(n%256).to_string()<<"\n";
	return 0;
}
