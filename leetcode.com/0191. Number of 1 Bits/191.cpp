/*
 * 191.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */


// 直接用bitset先



class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }
};
