/*
 * 115.cpp
 *
 *  Created on: Sep 13, 2018
 *      Author: frank
 */
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

class Solution {
public:
    int numDistinct(string s, string t) {
    	result_ = 0;
    	s_ = &s;
    	t_ = &t;
    	visited_.clear();

    	DFS(0, 0);
    	return result_;
    }
private:
    bool DFS(int i, int j)
    {
    	const string& s = *s_;
    	const string& t = *t_;

    	if(j >= t.length())
    	{
    		++result_;
    		return true;
    	}

    	if(i >= s.length())
    		return false;

    	bool ret1 = false;

    	if(s[i] == t[j])
    	{
    		auto it = visited_.find({i+1, j+1});
    		if(it == visited_.end())
    		{
    			ret1 = DFS(i+1, j+1);
    			if(! ret1)
    				visited_.insert({{i+1, j+1}, false});
    		}
    	}

    	bool ret2 = false;
		auto it = visited_.find({i+1, j});
		if(it == visited_.end())
		{
			ret2 = DFS(i+1, j);
			if(!ret2)
				visited_.insert({{i+1, j}, false});
		}

    	return ret1 || ret2;
    }
private:
    int result_;
    const string* s_;
    const string* t_;
    std::unordered_map<std::pair<int, int>, bool, pairhash> visited_;
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	int ret = ps->numDistinct("aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe",
			"bddabdcae");
	cout<<"ret="<<ret<<"\n";
	return 0;
}

