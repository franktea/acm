/*
 * 8.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: frank
 */
#include <string>
#include <iostream>
#include <limits>

using namespace std;

// 虽然是非常简单的题，用一个状态的状态机就可以解决，但是要注意末尾的边界问题，就是对于最正常的以数字结束的输入，
// 比如说"42", "-42"，要注意能够输出结果

class Solution {
public:
    int myAtoi(string str) {
        bool started = false;
        bool negative = false;
        int value = 0;
        for(int i = 0; i < str.length(); ++i)
        {
        		if(str[i] == ' ')
        		{
        			if(started)
        				return negative ? -value : value;
        		}
        		else if(str[i] == '+')
        		{
        			if(started)
        				return negative ? -value : value;
        			else
        				started = true;
        		}
        		else if(str[i] == '-')
        		{
        			if(started)
        				return negative ? -value : value;
        			else
        			{
        				started = true;
        				negative = true;
        			}
        		}
        		else if(str[i] >= '0' && str[i] <= '9')
        		{
        			started = true;
        			int new_value = value * 10 + (str[i] - '0');
        			if(new_value && (new_value / 10 != value)) // 越界了
        			{
        				return negative ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
        			}
        			value = new_value;
        		}
        		else
        		{
        			return negative ? -value : value;
        		}
        }

        return negative ? -value : value;
    }
};

int main()
{
	Solution* ps = new Solution;
	int ret = ps->myAtoi("42");
	cout<<"ret="<<ret<<"\n";
	return 0;
}



