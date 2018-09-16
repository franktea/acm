/*
 * 31.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: frank
 */




class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(! std::next_permutation(nums.begin(), nums.end()))
            std::sort(nums.begin(), nums.end());
    }
};
