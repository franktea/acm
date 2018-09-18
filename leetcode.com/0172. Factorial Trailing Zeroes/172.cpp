/*
 * 172.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */

#include <iostream>

using namespace std;

// 每多一个5，结果中就会多一个0，比如说5、10、15、20，
// 但是注意，25=5*5，除以5以后又多了一个5，同理，5*5*5多了2个5。

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while(n)
        {
        	int tmp = n / 5;
        	ret += tmp;
        	n = tmp;
        }
        return ret;
    }
};

int main()
{
	cout<<Solution().trailingZeroes(200)<<"\n";
	return 0;
}


