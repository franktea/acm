/*
 * 17.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: frank
 */
#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 用的是纯递归方法，居然速度很快。下次试试改成栈的方法

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	vector<string> result;
    	if(digits.empty()) return result;

    	vector<string> dict = {"", "",
    			"abc",
				"def",
				"ghi",
				"jkl",
				"mno",
				"pqrs",
				"tuv",
				"wxyz"};
    	vector<char> result_string;
    	result_string.resize(digits.size());
    	Next(0, digits, dict, result_string, result);
    	return result;
    }
private:
    void Next(size_t index, const string& digits, const vector<string>& dict,
    		vector<char>& result_string, vector<string>& result)
    {
    	if(index == digits.size())
    	{
    		result.push_back(string(result_string.begin(), result_string.end()));
    		return;
    	}

    	int v = digits[index] - '0';
    	for(char c: dict[v])
    	{
    		result_string[index] = c;
    		Next(index + 1, digits, dict, result_string, result);
    	}
    }
};

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();


int main()
{
	Solution s;
	string digits = "234";
	vector<string> v = s.letterCombinations(digits);
	for(const string& s: v)
	{
		cout<<s<<"\n";
	}
	return 0;
}



