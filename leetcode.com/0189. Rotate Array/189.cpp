/*
 * 189.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int distance = nums.size() - k % nums.size();

        std::rotate(nums.begin(), nums.begin() + distance, nums.end());
    }
};
