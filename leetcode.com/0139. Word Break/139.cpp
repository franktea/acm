/*
 * 139.cpp
 *
 *  Created on: Sep 17, 2018
 *      Author: frank
 */
#include <vector>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

// 用dfs，对于数据量大的case超时

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	return DFS(0, s, wordDict);
    }
private:
    // index is index in string s
    bool DFS(int index, const string& s, const vector<string>& dict)
    {
    	if(index >= s.length())
    		return true;

    	for(int i = 0; i < dict.size(); ++i)
		{
    		if(int(s.length())-index >= dict[i].length() &&
    				0 == memcmp(&s[0]+index, &dict[i][0], dict[i].length()))
    		{
    			bool ret = DFS(index + dict[i].length(), s, dict);
    			if(ret)
    				return ret;
    		}
		}

    	return false;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	vector<string> v = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	bool ret = ps->wordBreak(s, v);
	cout<<"ret="<<ret<<"\n";
	return 0;
}


