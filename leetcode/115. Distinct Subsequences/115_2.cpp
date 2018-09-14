/*
 * 115_2.cpp
 *
 *  Created on: Sep 14, 2018
 *      Author: frank
 */
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <cstring>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
    	s_ = &s;
    	t_ = &t;
    	memset(arr, -1, sizeof(arr));
//    	for(int i = 0; i < 100; ++i)
//    	{
//    		for(int j = 0; j < 100; ++j)
//    		{
//    			cout<<arr[i][j]<<", ";
//    		}
//    		cout<<"\n";
//    	}

    	int ret = DFS(0, 0);

    	for(int i = 0; i <= s.length()+1; ++i)
    	{
    		for(int j = 0; j <= t.length(); ++j)
    		{
    			cout<<arr[i][j]<<", ";
    		}
    		cout<<"\n";
    	}

    	return ret;
    }
private:
    int DFS(int i, int j)
    {
    	const string& t = *t_;
    	const string& s = *s_;

    	if(j >= t.length())
    		return 1;

    	if(i >= s.length())
    		return 0;

    	int result = 0;
    	if(s[i] != t[j])
    	{
    		if(arr[i+1][j] == -1)
    		{
    			int ret = DFS(i+1, j);
    			arr[i+1][j] = ret;
    		}
    		result = arr[i+1][j];

    	}
    	else
    	{
    		if(arr[i+1][j] == -1)
    		{
    			int ret = DFS(i+1, j);
    			arr[i+1][j] = ret;
    		}
    		result += arr[i+1][j];

    		if(arr[i+1][j+1] == -1)
    		{
    			int ret = DFS(i+1, j+1);
    			arr[i+1][j+1] = ret;
    		}
    		result += arr[i+1][j+1];
    	}

    	return result;
    }
private:
    const string* s_;
    const string* t_;
    int arr[100][100];
};

int main()
{
	Solution* ps = new Solution;
	int ret = ps->numDistinct("babgbag", "bag");
	cout<<"ret="<<ret<<"\n";
	return 0;
}



