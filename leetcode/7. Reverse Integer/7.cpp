/*
 * 7.cpp
 *  7. Reverse Integer
 *  Created on: Sep 1, 2018
 *      Author: frank
 */
#include <iostream>

using namespace std;

// 这个问题唯一要注意的点是对于中途出现越界的情况，需要直接返回0
// 直接暴力法，效率只打败35%

class Solution {
public:
    int reverse(int x) {
    	bool negative = x < 0;
    	if(negative)
    		x = -x;

    	int result = 0;
    	while(x > 0)
    	{
    		int v = x % 10;
    		x = x / 10;
    		int new_result = result*10;
    		if(new_result/10 != result) // 越界了
    		{
    			return 0;
    		}
    		result = new_result + v;
    	}

    	if(negative)
    		result = -result;

    	return result;
    }
};

int main()
{
	Solution* ps = new Solution;
	int ret = ps->reverse(123456);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



