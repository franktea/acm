/*
 * 264.cpp
 *
 *	uva 264 - Count on Cantor
 *
 *  Created on: Feb 23, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <cmath>

using namespace std;

/* 这个题目通过的人很多，应该是很简单，但是刚开始一直没看懂题目，
 * 后来发现如果把题目的三角形样子用等边三角形画就清楚了，
 * 第n行有n个元素，并且第n行的每个元素的两个数字之和都是n+1。
 * 前n行元素总个数为：n(n+1)/2，
 * 根据题目的输入x，用x＝n(n+1)/2先求得元素所在的行n，
 * 在求得元素所在的列，就可以输出结果了。
 *
 * 注意：题目中数元素个数的方向：奇数层是从左往右数，偶数层是从右往左数。
 */

int main()
{
	int32_t x;
	while(cin>>x)
	{
		double n = (sqrt(1.0+8.0*x) - 1.0)/2.0;
		int32_t int_n = (int32_t)n; // 输入的元素所在的行
		if(x != int_n*(int_n+1)/2) int_n += 1;
		int32_t col = x - int_n*(int_n-1)/2; // 输入的元素x所在的列
		if(int_n % 2) // 奇数层从左向右
			cout<<"TERM "<<x<<" IS "<<int_n+1-col<<"/"<<col<<"\n";
		else // 偶数层从右向左
			cout<<"TERM "<<x<<" IS "<<col<<"/"<<int_n+1-col<<"\n";
	}
	return 0;
}



