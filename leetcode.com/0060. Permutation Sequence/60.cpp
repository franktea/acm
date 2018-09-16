/*
 * 60.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 用了最傻的方法，当然这种方法很慢。

class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for(int i = 0; i < n; ++i)
        	str.append(std::to_string(i+1));

        for(int i = 1; i < k; ++i)
        	std::next_permutation(str.begin(), str.end());

        return str;
    }
};

int main()
{
	return 0;
}



