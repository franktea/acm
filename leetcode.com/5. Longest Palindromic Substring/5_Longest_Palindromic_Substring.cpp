/*
 * 5_Longest_Palindromic_Substring.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: frank
 */
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// 第一次，暴力求接法，复杂度为O(n^3)
// 下次要寻求更好的解法

class Solution {
public:
    string longestPalindrome(string s) {
    	int max_len = 0;
    	string result = "";
        for(int i = 0; i < s.size(); ++i)
        {
        		for(int j = i; j < s.size(); ++j)
        		{
        			if(!IsPalindrome(s, i, j))
        			{
        				continue;
        			}

        			int len = j - i + 1;
        			if(len > max_len)
        			{
        				max_len = len;
        				result = s.substr(i, len);
        			}
        			else if(len == max_len)
        			{
        				string tmp = s.substr(i, len);
        				if(tmp < result)
        					result = tmp;
        			}
        		}
        }
        return result;
    }
private:
    bool IsPalindrome(const string& s, int i, int j)
    {
    	while(i < j)
    	{
    		if(s[i] != s[j])
    			return false;
    		++i;
    		--j;
    	}

    	return true;
    }
};

int main()
{
	Solution* ps = new Solution;
	string s = ps->longestPalindrome("cbbd");
	cout<<"result:"<<s<<"\n";
	return 0;
}


