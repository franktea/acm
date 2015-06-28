/*
 * 10137.cpp
 *
 *	uva 10137 - The Trip
 *
 *  Created on: Jun 7, 2015
 *      Author: frank
 */
#include <locale>
#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

///**
// * cin的自定义demiliter，这个地方设置"."为分割符，
// * 将整数部分和小数部分分开。
// * 这种方法的出处来自：
// * http://stackoverflow.com/questions/7302996/changing-the-delimiter-for-cin-c
// */
//struct colon_is_space : std::ctype<char> {
//  colon_is_space() : std::ctype<char>(get_table()) {}
//  static mask const* get_table()
//  {
//    static mask rc[table_size];
//    rc['.'] = std::ctype_base::space;
//    rc['\n'] = std::ctype_base::space;
//    return &rc[0];
//  }
//};

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	//cin.imbue(locale(cin.getloc(), new colon_is_space));

	vector<double> numbers;
	int32_t count;
	while(cin>>count && count)
	{
		double sum = 0;
		numbers.reserve(count);
		numbers.clear();
		double number;
		while(count--)
		{
			cin>>number;
			sum += number;
			numbers.push_back(number);
		}
        double average = sum / numbers.size();
		double positive = 0;
		double negative = 0;
		for(auto it = numbers.begin(); it != numbers.end(); ++it)
		{
			if(*it > average)
			{
				positive += int(100*(*it - average))/100.0;
			}
			else
			{
				negative += int(100*(average - *it))/100.0;
			}
		}

		const double result = std::max(negative, positive);
		printf("$%.2f\n",result);
	}

	return 0;
}

