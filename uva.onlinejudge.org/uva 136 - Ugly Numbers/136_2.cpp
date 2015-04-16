/*
 * 136_2.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;

int main()
{
	vector<int32_t> ugly;
	ugly.reserve(2000); // 用一个数组按顺序记录所有的ugly number， 直到第1500个
	ugly.push_back(1); // 把1放到数组里面去
	// 么个新的ugly number都是前面某个数字乘以2、3或者5得到，
	// 用3个变量分别表示当前的乘2、3、5的位置（就是数组下标），刚开始都是0
	int32_t index2 = 0, index3 = 0, index5 = 0;
	while(ugly.size() < 1500)
	{
		int32_t min_now = ugly[ugly.size() - 1];
		while(ugly[index2] * 2 <= min_now) ++ index2;
		while(ugly[index3] * 3 <= min_now) ++ index3;
		while(ugly[index5] * 5 <= min_now) ++ index5;
		int32_t min_2 = ugly[index2] * 2;
		int32_t min_3 = ugly[index3] * 3;
		int32_t min_5 = ugly[index5] * 5;
//		cout<<min_now<<" "<<min_2<<" "<<min_3<<" "<<min_5<<"||"<<index2<<
//				" "<<index3<<" "<<index5<<endl;
		if(min_2 <= min_3 && min_2 <= min_5)
		{
			ugly.push_back(min_2);
			++ index2;
		}
		else if(min_3 <= min_2 && min_3 <= min_5)
		{
			ugly.push_back(min_3);
			++ index3;
		}
		else
		{
			ugly.push_back(min_5);
			++ index5;
		}
 	}
	cout<<"The 1500'th ugly number is "<<ugly[1499]<<"."<<"\n";
	return 0;
}


