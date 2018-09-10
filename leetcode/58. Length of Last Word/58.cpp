/*
 * 58.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */




class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int len = 0;
        int index = s.size() - 1;
        while(index >= 0 && !std::isalpha(s[index]))
            --index;
        if(index < 0) // 注意边界
            return 0;
        while(index >= 0 && std::isalpha(s[index]))
        {
            --index;
            ++len;
        }
        return len;
    }
};
