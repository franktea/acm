/*
 * 72.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
    	vector<vector<int>> matrix;
    	matrix.resize(word1.size()+1);
    	for(vector<int>& v: matrix)
    		v.resize(word2.size()+1);

    	matrix[word1.size()][word2.size()] = 0;
    	for(int j = 0; j < word2.size(); ++j)
    		matrix[word1.size()][j] = int(word2.length()) - j;

    	for(int i = 0; i < word2.length(); ++i)
    		matrix[i][word2.size()] = word1.length() - i;

    	for(int i = word1.length() - 1; i >= 0; --i)
    	{
    		for(int j = word2.length() - 1; j >= 0; --j)
    		{
    			if(word1[i] == word2[j])
    				matrix[i][j] = matrix[i+1][j+1];
    			else
    			{
    				int d1 = matrix[i+1][j] + 1; // delete
    				int d2 = matrix[i][j+1] + 1; // insert
    				int d3 = matrix[i+1][j+1] + 1; // replace
    				matrix[i][j] = std::min(d1, std::min(d2, d3));
    			}
    		}
    	}

    	return matrix[0][0];
    }
private:
    int Distance(int i, int j, const string& s, const string& t) // 直接用递归会超时
    {
    	if(i >= s.length() && j >= t.length())
    		return 0;

    	if(j >= t.length()) // and i < s.length
    		return int(s.length()) - i;

    	if(i >= s.length())
    		return int(t.length()) - j;

    	if(s[i] == t[j])
    		return Distance(i+1, j+1, s, t);
    	else
    	{
    		const int d1 = Distance(i+1, j, s, t) + 1; // delete
    		const int d2 = Distance(i, j+1, s, t) + 1; // insert
    		const int d3 = Distance(i+1, j+1, s, t) + 1; // replace
    		return std::min(d1, std::min(d2, d3));
    	}
    }
};

int main()
{
	Solution* ps = new Solution;
	int ret = ps->minDistance("plasma", "altruism");
	cout<<"ret="<<ret<<"\n";
	return 0;
}



