/*
 * 160.cpp
 *
 *  uva 160 - Factors and Factorials
 *
 *  Created on: Jan 10, 2016
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

class Number
{
public:
	Number(int32_t num): number_(num) {}

	// 分解质因数
	// 参考这里：http://www.cnblogs.com/youxin/p/3232049.html
	void Generate()
	{
		int32_t number = number_;
		for(int32_t i = 2; i <= number; )
		{
			while(number % i == 0)
			{
				num_count_[i] ++;
				number /= i;
			}

			i = (i == 2)? 3 : i + 2;
		}
	}

	const std::map<int32_t, int32_t>& NumberCountMap() const
	{
		return num_count_;
	}
private:
	const int32_t number_;
	std::map<int32_t, int32_t> num_count_;
};

std::map<int32_t, Number> all_numbers;

void GenerateAllNumbers()
{
	for(int32_t i = 2; i <= 100; ++i)
	{
		all_numbers.insert(std::make_pair(i, Number(i)));
	}

	for(auto i = all_numbers.begin();
			i != all_numbers.end(); ++i)
	{
		i->second.Generate();
	}
}

void Solve(int32_t input)
{
	std::map<int32_t, int32_t> prime_count;

	for(int32_t i = 2; i <= input; ++i)
	{
		const Number& nb = all_numbers.find(i)->second;
		for(auto it = nb.NumberCountMap().begin();
				it != nb.NumberCountMap().end(); ++it)
		{
			prime_count[it->first] += it->second;
		}
	}

	cout<<std::right<<std::setw(3)<<input<<"! =";
	int32_t line_count = 0; // 每行最多输出15个，15个以后就要换行，擦
	for(auto i = prime_count.begin(); i != prime_count.end(); ++i)
	{
		if(line_count > 0 && line_count % 15 == 0)
		{
			cout<<"\n      ";
		}
		cout<<std::right<<std::setw(3)<<i->second;
		++ line_count;
	}
	cout<<"\n";
}

int main()
{
	GenerateAllNumbers();
	int32_t input;
	while(cin>>input && input)
	{
		Solve(input);
	}

	return 0;
}


