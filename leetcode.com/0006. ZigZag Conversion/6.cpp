/*
 * 6.cpp
 *
 *  Created on: Sep 17, 2018
 *      Author: frank
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	vector<vector<char>> matrix;
    	matrix.resize(numRows);
    	for(vector<char>& v: matrix)
    	{
    		v.resize(s.length(), ' ');
    	}

    	int y = 0;
    	int x = 0;
    	int direction = 0; // 0 move down , 1 move up to top right
    	for(char c: s)
    	{
    		matrix[y][x] = c;
    		if(direction == 0)
    		{
    			++y;
    			if(y >= numRows)
    			{
    				y-=2;
    				++x;
    				if(y < 0)
    					y = 0;
    				direction = 1;
    			}
    		}
    		else // move up
    		{
    			--y;
    			++x;
    			if(y <= 0)
    			{
    				y = 0;
    				direction = 0;
    			}
    		}
    	}

    	for(vector<char>& v: matrix)
    	{
    		for(char c: v)
    			cout<<c;
    		cout<<"\n";
    	}

    	string result;
    	result.reserve(s.length());
    	for(vector<char>& v: matrix)
    	{
    		for(char c: v)
    		{
    			if(c == ' ')
    				continue;
    			result.push_back(c);
    		}
    	}

    	return result;
    }
};

int main()
{
	Solution* ps = new Solution;
	string ret = ps->convert("PAYPALISHIRING", 4);
	cout<<ret<<"\n";
	ret = ps->convert("ABCD", 3);
	cout<<ret<<"\n";
	return 0;
}



