/*
 * 202.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

using namespace std;

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
	auto f = [&](vector<Result>::iterator it) {
		cout<<numerator<<"/"<<denominator<<" = "<<before_dot<<".";
		for(auto i = v.begin(); i != it; ++i)
		{
			cout<<i->quotient;
		} };

	if(0 == remainder) // 坑之所在：对于可以整除的情况，要输出x.(0)，而不是x.0(0)
	{
		f(v.end());
		cout<<"(0)"<<"\n";
		cout<<"   1 = number of digits in repeating cycle"<<"\n";
		return;
	}

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
			f(v.end());
			cout<<"(0)"<<"\n";
			cout<<"   1 = number of digits in repeating cycle"<<"\n";
			break;
		}
		else // 在vector中有没有相同的余数，如果找到，则说明循环已经开始
		{
			auto it = std::find_if(v.begin(), v.end(),
					[remainder](const Result& r) { return r.remainder == remainder; });
			if(it != v.end()) // 找到了
			{
				//cout<<"ended, index="<<it-v.begin()<<", length="<<v.end()-it<<endl;
				f(it);
				cout<<"(";
				for(auto i = it; i != v.end(); ++i)
				{
					cout<<i->quotient;
					if(i-v.begin() >= 49) // 小数部分最多显示50位，而不是循环部分显示50位
					{
						cout<<"...";
						break;
					}
				}
				cout<<")\n";
				cout<<"   "<<v.end()-it<<" = number of digits in repeating cycle"<<"\n";
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
		//cout<<"now=>"<<numerator<<" "<<denominator<<endl;
		Solve(numerator, denominator);
		cout<<"\n"; //题目最后一句，没注意看就是巨大的坑：Print a blank line after every test case.
	}

	return 0;
}


