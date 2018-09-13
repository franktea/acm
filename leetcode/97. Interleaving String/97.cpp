/*
 * 97.cpp
 *
 *  Created on: Sep 13, 2018
 *      Author: frank
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	if(s1.length() + s2.length() != s3.length())
    		return false;

    	s1_ = &s1;
    	s2_ = &s2;
    	s3_ = &s3;
    	visited_.clear();

    	return DFS(0, 0, 0);
    }
private:
    bool DFS(int index1, int index2, int index3)
    {
    	const string& s1 = *s1_;
    	const string& s2 = *s2_;
    	const string& s3 = *s3_;

    	//cout<<index1<<", "<<index2<<", "<<index3<<"\n";

    	if(index1 >= s1.length() && index2 >= s2.length() && index3 >= s3.length())
    	{
    		return true;
    	}

    	bool result = false;
    	if(index1 < s1.length() && s3[index3] == s1[index1])
    	{
    		std::tuple<int, int, int> arr = {index1+1, index2, index3+1};
    		if(visited_.find(arr) == visited_.end())
    		{
				result = DFS(index1+1, index2, index3+1);
				if(!result)
				{
					visited_.insert(arr);
				}
    		}
    	}

    	if(result) return result;
    	if(index2 < s2.length() && s3[index3] == s2[index2])
    	{
    		std::tuple<int, int, int> arr = {index1, index2+1, index3+1};
    		if(visited_.find(arr) == visited_.end())
    		{
				result = DFS(index1, index2+1, index3+1);
				if(!result)
				{
					visited_.insert(arr);
				}
    		}
    	}

    	return result;
    }
private:
    string* s1_;
    string* s2_;
    string* s3_;
    std::set<std::tuple<int, int, int>> visited_;
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	bool ret = ps->isInterleave("aabcc", "dbbca", "aadbbbaccc");
	cout<<"ret="<<ret<<"\n";
	return 0;
}

