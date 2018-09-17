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

// 递归，用备忘录方法，居然打败100%。
// 题解中已经给出了递推公式，改成自顶向下的循环dp很简单。

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	visited_.clear();
    	visited_.resize(s.length()+1, -1);
    	bool ret = DFS(0, s, wordDict);
//    	for(int i: visited_)
//    		cout<<i<<", ";
//    	cout<<"\n";
    	return ret;
    }
private:
    // index is index in string s
    bool DFS(int index, const string& s, const vector<string>& dict)
    {
    	//cout<<"index="<<index<<"\n";
    	if(index >= s.length())
    		return true;

    	for(int i = 0; i < dict.size(); ++i)
		{
    		if(int(s.length())-index >= dict[i].length() &&
    				0 == memcmp(&s[0]+index, &dict[i][0], dict[i].length()))
    		{
    			const int next_index = index + dict[i].length();
    			if(visited_[next_index] == -1)
    			{
    				bool ret = DFS(index + dict[i].length(), s, dict);
    				if(ret)
    				{
    					visited_[next_index] = 1;
    					return ret;
    				}
    				else
    				{
    					visited_[next_index] = 0;
    				}
    			}
    			else if(visited_[next_index] == 0)
    			{
    				continue;
    			}
    			else // 1
    			{
    				return true;
    			}
    		}
		}

    	return false;
    }
private:
    vector<int> visited_;
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	bool ret;
	Solution* ps = new Solution;
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	vector<string> v = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	ret = ps->wordBreak(s, v);
	cout<<"ret="<<ret<<"\n";
	string s2 = "applepenapple";
	vector<string> v2 = {"apple", "pen"};
	ret = ps->wordBreak(s2, v2);
	cout<<"ret="<<ret<<"\n";
	return 0;
}


