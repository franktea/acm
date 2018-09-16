/*
 * 3_Longest_Substring_Without_Repeating_Characters.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: frank
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 字符的范围肯定属于[0, 127]，用大小为128的数组来记录有没有重复的字符
// 复杂度为O(n^2)
// 这种方法貌似还不够快，以后再想想有没有更快的方法

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	if(s.empty()) return 0;
    	if(s.size() == 1) return 1;
    	int result = 1;
        for(int i = 0; i < s.size(); ++i)
        {
        		int times[128] = {0};
        		int max_len = 0;
        		++times[s[i]];
        		for(int j = i + 1; j < s.size(); ++j)
        		{
        			++times[s[j]];
        			if(times[s[j]] > 1)
        			{
        				break;
        			}
        			max_len = j - i + 1;
        		}

        		result = std::max(result, max_len);
        }
        return result;
    }
};

int main()
{
	string s = "abcabcbb";
	Solution* ps = new Solution;
	int ret = ps->lengthOfLongestSubstring(s);
	cout<<"ret="<<ret<<"\n";
	return 0;
}


