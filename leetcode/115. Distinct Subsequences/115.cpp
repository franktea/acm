/*
 * 115.cpp
 *
 *  Created on: Sep 13, 2018
 *      Author: frank
 */
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 未解决：
 * 遍历，如果遍历到pattern的末尾，说明找到一个匹配。
 * 如果记录了可以访问的状态，则会超时，如果不记录状态，又算不出正确的结果。
 */

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
    		if(it == visited_.end() || it->second == false)
    		{
    			ret1 = DFS(i+1, j+1);
    			visited_.insert({{i+1, j+1}, ret1});
    		}
    		else
    			ret1 = true;
    	}

    	bool ret2 = false;
		auto it = visited_.find({i+1, j});
		if(it == visited_.end() || it->second == false)
		{
			ret2 = DFS(i+1, j);
			visited_.insert({{i+1, j}, ret2});
		}
		else
		{
			ret2 = true;
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

