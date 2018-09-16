/*
 * 91.cpp
 *
 *  Created on: Sep 13, 2018
 *      Author: frank
 */

#include <string>
#include <iostream>

using namespace std;


//从前往后扫描，最后一个数字放进前面已有的结果中，有两种放法：
// 1: 将单个数字直接到每个结果的后面，该组合的个数与f(n-1)相同
// 2：将单个的数字与上一个数字组合一个两位数，该组合的个数等于f(n-2)的个数。
// f(n) = f(n-1) // 最后两位数>26
// f(n) = f(n-1) + f(n - 2) // 最后两位数 < 26
// 比较恶心的是要考虑0的情况，所有的数字0只能与前面的1或者2组合，否则为非法。0单独存在也是非法。

class Solution {
public:
    int numDecodings(string s) {
       if(s.empty()) return 0;
       int c0 = s[0] == '0' ? 0 : 1;
       if(s.size() == 1) return c0;

       int c1 = 0;
       if(s.size() >= 2)
       {
    	   if(s[0] == '0')
    		   return 0;
    	   if(s[1] == '0')
    		   c1 = stoi(s.substr(0, 2)) <= 26 ? 1 : 0;
    	   else
    		   c1 = stoi(s.substr(0, 2)) <= 26 ? 2 : 1;
       }

       if(c1 == 0) return 0;

       for(int i = 2; i < s.length(); ++i)
       {
    	   int c = 0;
    	   if(s[i] == '0')
    	   {
    		   if(s[i-1] == '0')
    			   return 0;
    		   if(stoi(s.substr(i-1, 2)) > 26)
    			   return 0;
    		   c = c0;
    	   }
    	   else
    	   {
    		   if(s[i-1] == '0')
    			   c = c1;
    		   else
    			   c = c1 + (stoi(s.substr(i-1, 2)) <= 26 ? c0 : 0);
    	   }
    	   c0 = c1;
    	   c1 = c;
       }

       return c1;
    }
};

int main()
{
	Solution* ps = new Solution;
	int ret = ps->numDecodings("1120226");
	cout<<"ret="<<ret<<"\n";
	return 0;
}


