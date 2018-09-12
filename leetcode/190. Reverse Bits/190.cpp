/*
 * 190.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */


// 直接用bitset不对，应该是字节序的问题

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bs(n);
        for(size_t index = 0; index < 16; ++index)
        {
            auto tmp = bs[31-index];
            bs[31-index] = bs[index];
            bs[index] = tmp;
        }
        return bs.to_ulong();
    }
};
