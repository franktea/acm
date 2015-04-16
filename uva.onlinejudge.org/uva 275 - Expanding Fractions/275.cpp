/*
 * 275.cpp
 *
 *  uva 275 - Expanding Fractions
 *
 *  Created on: Feb 22, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 与uva 202 的方法一样， 只是输出有少许差别，
 * 而且本题保证输入是2个正整数。
 *
 * 本题的坑主要是50个字符换行的问题，小数点后面刚好是99位时(包括小数点就是100位)，
 * 按照习惯会输出2个换行，但是结果要求只需要一个换行。
 * 用1 397 输入就可以测试此坑。
 */

// 每次除法的中间结果，需要保存起来。
struct Result
{
	int32_t remainder; // 余数，提供查询，如果发现有任何重复的余数，则说明小数循环部分已经找到
	int32_t quotient; // 商
};

void Solve(int32_t numerator, int32_t denominator)
{
	vector<Result> v;
	v.reserve(1024);
	int32_t before_dot = numerator / denominator; // 小数点前面的部分
	int32_t remainder = numerator % denominator;

	// 用lambda函数很方便定义局部函数，而且访问外部的变量也很方便
	// 定义一个输出小数循环部分前面的局部函数
	auto f = [&v]() {
		cout<<".";
		for(auto i = v.begin(); i != v.end(); ++i)
		{
			if( (i - v.begin() + 1) % 50 == 0 ) cout<<"\n";
			cout<<i->quotient;
		} };

	// 计算小数点和后面的部分
	while(1)
	{
		int32_t new_remainder = remainder * 10;
		int32_t quotient = new_remainder / denominator;
		v.push_back({remainder, quotient});
		remainder = new_remainder % denominator;
		if(0 == remainder) // 已经除尽了
		{
			//cout<<"除尽了"<<endl;
			f();
			cout<<"\nThis expansion terminates."<<"\n";
			break;
		}
		else // 在vector中有没有相同的余数，如果找到，则说明循环已经开始
		{
			auto it = std::find_if(v.begin(), v.end(),
					[remainder](const Result& r) { return r.remainder == remainder; });
			if(it != v.end()) // 找到了
			{
				//cout<<"ended, index="<<it-v.begin()<<", length="<<v.end()-it<<endl;
				f();
				cout<<"\nThe last "<<v.end()-it<<" digits repeat forever.\n";
				break;
			}
		}
	}
}

int main()
{
	int32_t numerator; // 分子
	int32_t denominator; // 分母
	while(cin>>numerator>>denominator)
	{
		if(0 == numerator && 0 == denominator) break;

		Solve(numerator, denominator);
		cout<<"\n";
	}

	return 0;
}
