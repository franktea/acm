/*
 * 9.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: frank
 */
#include <string>
#include <iostream>

using namespace std;

// 非常简单的题，转成string来做，效率达到了平均水平

class Solution {
public:
    bool isPalindrome(int x) {
    	if(x < 0) return false;
    	if(x == 0) return true;

    	string s = std::to_string(x);
    	for(int i = 0, j = s.size() - 1; i < j; ++i, --j)
    	{
    		if(s[i] != s[j])
    			return false;
    	}

    	return true;
    }
};

int main()
{
	return 0;
}



