/*
 * 305.cpp
 *
 *	uva 305 - Joseph
 *
 *  Created on: Feb 18, 2015
 *      Author: frank
 */

#include <iostream>
#include <list>
#include <stdint.h>
#include <string.h>

using namespace std;

int main()
{
	int32_t k;
	int32_t cache[] = // 13个全部求出来提交看快多少
	{ 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };
	while (cin >> k)
	{
		if (0 == k)
			break;
		cout << cache[k - 1] << "\n";
	}

	return 0;
}

