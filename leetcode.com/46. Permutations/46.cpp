/*
 * 46.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */

// 用了std::next_permutation

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        }while(std::next_permutation(nums.begin(), nums.end()));
        return result;
    }
};


