/*
 * 107.cpp
 *
 *	uva 107 The Cat in the Hat
 *
 *  Created on: Feb 17, 2015
 *      Author: frank
 */


#include <cmath>
#include <iostream>
#include <stdint.h>

using namespace std;

/**
 * 满N叉树，假设数的高度为h＋1，则输入的2个数分别为：
 * (N+1)**h N**h
 * 第一个猫的高度，为(N+1)的h次方；
 * 叶子节点的个数，为N的次方。
 * 设输入为a b，则
 * (N+1)**h = a
 * N**h = b
 * 为2元方程，不好直接求解，但是因为全部是整数，可以尝试用遍历的方法
 */

int main()
{
	double n, h, a, b;
	while(cin>>a>>b)
	{
		if(a == 0 && b == 0) break;
		n = 1;
		while(std::abs(log(a)/log(n+1) - log(b)/log(n)) > 1e-7)
			++n;

		h = log(a)/log(n+1);

		if(std::abs(n - 1) < 1e-7) // n == 1
		{
			cout<<h;
		}
		else
		{
			cout<<int32_t(0.5 + (pow(n, h) - 1)/(n-1));//double转成int如果不加0.5就通不过
		}
		// 输出所有猫的高度和，就是等比数列的和：
		// 1*n**h + (n+1)*n**(h-1)+ (n+1)**2*n**(h-1) + ... + (n+1)**h * n**0
		cout<<" "<<int32_t(0.5 + pow(n+1, h+1) - pow(n, h+1))<<"\n";
	}

	return 0;
}

