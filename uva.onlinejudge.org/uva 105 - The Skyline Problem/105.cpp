/*
 * 105.cpp
 *  uva 105 - The Skyline Problem
 *  Created on: Feb 11, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

int main()
{
	// 用最傻的方法，题目说了坐标不超过1w，并且都是整数，那就建长度为1w的数组
    vector<int32_t> all(10001, 0);
    int32_t x1, x2, h;
    while(cin>>x1>>h>>x2)
    {
    	for(int32_t x = x1; x < x2; ++x)
    	{
    		if(all[x] < h) all[x] = h;
    	}
    }

    int32_t current_h = 0;
    bool first_printed = false; // 最后不能有空格
    for(size_t x = 0; x < all.size(); ++x)
    {
    	if(all[x] == current_h) continue;

    	if(!first_printed)
    	{
    		cout<<x<<" "<<all[x];
    		first_printed = true;
    	}
    	else
    	{
    		cout<<" "<<x<<" "<<all[x];
    	}
    	current_h = all[x];
    }
    cout<<"\n";
    return 0;
}

