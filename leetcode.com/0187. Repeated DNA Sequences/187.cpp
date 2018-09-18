/*
 * 187.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

// time out

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    	vector<string> result;
    	set<string> all;
    	for(int i = 0; i + 1 <= s.length(); ++i)
    	{
    		string sub = s.substr(i, 10);
    		if(s.find(sub, i+1) != string::npos && (all.find(sub) == all.end()))
    		{
    			result.push_back(sub);
    			all.insert(sub);
    		}
    	}

    	return result;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution* ps = new Solution;
	vector<string> ret = ps->findRepeatedDnaSequences(s);
	for(const string& s: ret)
		cout<<s<<"\n";
	return 0;
}



