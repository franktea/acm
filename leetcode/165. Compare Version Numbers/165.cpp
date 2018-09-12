/*
 * 165.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 一次通过，打败100%，没啥好说的

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0;
        int index2 = 0;
        while(index1 < version1.length() && index2 < version2.length())
        {
        	int v1 = Next(version1, index1);
        	int v2 = Next(version2, index2);
        	if(v1 - v2)
        		return v1 > v2 ? 1 : -1;
        }

        if(index1 >= version1.length() && index2 >= version2.length())
        	return 0;

        if(index1 < version1.length())
        {
        	while(index1 < version1.length())
        	{
        		int v = Next(version1, index1);
        		if(v) // v != 0
        			return 1;
        	}
        }

        if(index2 < version2.length())
        {
        	while(index2 < version2.length())
        	{
        		int v = Next(version2, index2);
        		if(v)
        			return -1;
        	}
        }

        return 0;
    }
private:
    int Next(const string& str, int& index)
    {
    	int i = index;
    	while(i < str.length() && !std::isdigit(str[i]))
    		++i;

    	int j = i;
    	while(j < str.length() && std::isdigit(str[j]))
    		++j;

    	index = j;
    	return std::stoi(str.substr(i, j-i));
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	int ret = ps->compareVersion("7.5.2.4", "7.5.3");
	cout<<"ret="<<ret<<"\n";
	return 0;
}


