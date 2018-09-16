/*
 * 168.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 没有0，所以也并不是像喝汤一样简单

class Solution {
public:
    string convertToTitle(int n) {
    	vector<char> char_map;
    	char_map.resize(27);
    	for(char c = 'A';  c <= 'Z'; ++c)
    	{
    		char_map[c-'A'+1] = c;
    	}

    	string result;
    	while(n)
    	{
    		int v = (n-1) % 26;
    		n = (n-1) / 26;
    		result.push_back(char_map[v+1]);
    	}

    	std::reverse(result.begin(), result.end());
    	return result;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	string ret = ps->convertToTitle(28);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



