/*
 * 12.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: frank
 */
#include <string>
#include <iostream>
#include <map>

using namespace std;

// 用map来存，效果一般

class Solution {
public:
    string intToRoman(int num) {
    	map<int, string> values = {{1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"},
    			{10, "X"}, {20, "XX"}, {30, "XXX"}, {40, "XL"}, {50, "L"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"},
				{100, "C"}, {200, "CC"}, {300, "CCC"}, {400, "CD"}, {500, "D"}, {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"},
				{1000, "M"}, {2000, "MM"}, {3000, "MMM"}};
    	string result = "";

    	// 从千位数开始转，用一个因子来除，因子取值依次为1000、100、10、1
    	for(int divisor = 1000; num > 0; divisor = divisor/10)
    	{
    		int v = num / divisor;
    		num %= divisor;
    		if(v)
    			result.append(values[v*divisor]);
    	}

    	return result;
    }
};

int main()
{
	Solution* ps = new Solution;
	string ret = ps->intToRoman(3);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



