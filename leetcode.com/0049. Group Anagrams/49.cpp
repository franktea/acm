/*
 * 49.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: frank
 */
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, multiset<string>> all;
        for(const string& str: strs)
        {
            string tmp = str;
            std::sort(tmp.begin(), tmp.end());
            all[tmp].insert(str);
        }

        vector<vector<string>> result;
        for(auto it: all)
        {
        	const multiset<string>& st = it.second;
            vector<string> v;
            for(const string& s: st)
            {
                v.push_back(s);
            }
            result.push_back(v);
        }

        return result;
    }
};

static int fast = [](){std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	vector<string> v = {"eat","tea","tan","ate","nat","bat"};
	Solution* ps = new Solution;
	vector<vector<string>> vv = ps->groupAnagrams(v);
	for(const vector<string>& v: vv)
	{
		for(const string& s: v)
		{
			cout<<s<<", ";
		}
		cout<<"\n";
	}
	return 0;
}



