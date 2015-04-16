/*
 * ARITH.cpp
 *
 *  spoj: Simple Arithmetics
 *
 *  Created on: Apr 6, 2015
 *      Author: frank
 */

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stdint.h>
#include <stdlib.h>

using namespace std;

/**
 * 幸好在这里有大量的测试数据可以供校验：
 * http://contest.felk.cvut.cz/00cerc/solved/index.html
 */

class BigInt
{
public:
	BigInt() {}
	void FromString(const string& str)
	{
		numbers_.clear();
		numbers_.reserve(str.length());

		for(char c: str)
		{
			numbers_.push_back(c - '0');
		}
	}

	size_t DisplayWidth()
	{
		return numbers_.size();
	}

	BigInt operator+(const BigInt& bi) const
	{
		BigInt result;
		const BigInt& bi1 = bi.right_space_count_ < right_space_count_ ? bi : *this;
		const BigInt& bi2 = bi.right_space_count_ < right_space_count_ ? *this : bi;
		result.right_space_count_ = bi1.right_space_count_;
		size_t visible_number_count = std::max(bi1.numbers_.size(),
				bi2.numbers_.size() + bi2.right_space_count_ - bi1.right_space_count_);
		result.numbers_.reserve(visible_number_count + 1);
		result.numbers_.resize(visible_number_count);

		//cout<<"::::::::bi1:"<<bi1.ToString()<<endl;
		//cout<<"::::::::bi2:"<<bi2.ToString()<<endl;
		int32_t left_value = 0;
		for(int32_t i = visible_number_count - 1; i >= 0; --i)
		{
			int32_t value1 = bi1.FromRight(visible_number_count - i - 1);
			int32_t value2 = bi2.FromRight(visible_number_count - i - 1);
			//cout<<"value1: "<<value1<<", value2: "<<value2<<", left: "<<left_value<<endl;
			int32_t value = value1 + value2 + left_value;
			result.numbers_[i] = value % 10;
			left_value = value / 10;
		}
		if(left_value > 0)
			result.numbers_.insert(result.numbers_.begin(), left_value);

		return result;
	}

	BigInt operator-(const BigInt& bi) const
	{
		BigInt result;
		const BigInt& bi1 = bi.right_space_count_ < right_space_count_ ? bi : *this;
		const BigInt& bi2 = bi.right_space_count_ < right_space_count_ ? *this : bi;
		result.right_space_count_ = bi1.right_space_count_;
		size_t visible_number_count = std::max(bi1.numbers_.size(), bi2.numbers_.size() + bi2.right_space_count_ - bi1.right_space_count_);
		result.numbers_.reserve(visible_number_count + 1);
		result.numbers_.resize(visible_number_count);

		int32_t left_value = 0;
		for(int32_t i = visible_number_count - 1; i >= 0; --i)
		{
			int32_t value1 = bi1.FromRight(visible_number_count - i - 1);
			int32_t value2 = bi2.FromRight(visible_number_count - i - 1);
			//cout<<"value1: "<<value1<<", value2: "<<value2<<", left: "<<left_value<<endl;
			int32_t value = value1 - value2 - left_value;
			if(value < 0)
			{
				value += 10;
				left_value = 1;
			}
			else
			{
				left_value = 0;
			}
			result.numbers_[i] = value;
		}
		// delete all the leading zeros
		auto it = std::find_if(result.numbers_.begin(), result.numbers_.end(), [](int v) {return v != 0;});
		vector<int32_t> v(it, result.numbers_.end());
		result.numbers_.swap(v);

		return result;
	}

	BigInt Multiply(int32_t number, size_t right_space_count) const
	{
		BigInt result;
		result.right_space_count_ = right_space_count;
		result.numbers_.clear();
		if(number == 0 || (numbers_.size() == 1 && numbers_[0] == 0))
		{
			result.numbers_.push_back(0);
			return result;
		}
		result.numbers_.resize(numbers_.size());
		int32_t left_value = 0;
		for(int32_t i = numbers_.size() - 1; i >= 0; --i)
		{
			int32_t value = numbers_[i] * number + left_value;
			result.numbers_[i] = value % 10;
			left_value = value / 10;
		}
		if(left_value > 0)
			result.numbers_.insert(result.numbers_.begin(), left_value);
		return result;
	}

	string ToString() const
	{
		string result(numbers_.size(), ' ');
		for(size_t i = 0; i < numbers_.size(); ++i)
		{
			result[i] = numbers_[i] + '0';
		}
		return result;
	}

	size_t right_space_count() { return right_space_count_; }
private:
	int32_t FromRight(int32_t index) const
	{
		if(index < right_space_count_ || index >= right_space_count_ + numbers_.size())
			return 0;

		return numbers_[numbers_.size() + right_space_count_ - index - 1];
	}
private:
	vector<int32_t> numbers_;
	size_t right_space_count_ = 0;
};

struct OutPutList
{
public:
	void Add(const string& str, size_t right_sapce_count)
	{
		strings_.push_back(std::pair<string, size_t>{str, right_sapce_count});
	}

	void OutPut()
	{
		cout.flags(ios::right); //右对齐
		int32_t max_width = GetMaxWidth();
		for(std::pair<string, size_t>& p: strings_)
		{
			cout<<setw(max_width - p.second)<<p.first<<"\n";
		}
	}

	size_t GetMaxWidth()
	{
		size_t result = 0;
		for(std::pair<string, size_t>& p: strings_)
		{
			result = std::max(result, p.first.length() + p.second);
		}
		return result;
	}
private:
	list<std::pair<string, size_t> > strings_;
};

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int32_t count;
	cin>>count;
	string line;
	while(count--)
	{
		cin>>line;
		const std::size_t pos = line.find_first_not_of("0123456789");
		BigInt bi1;
		BigInt bi2;
		bi1.FromString(string(&line[0], pos));
		string str2 = string(&line[pos+1], line.length() - pos - 1);
		bi2.FromString(str2);
		if(line[pos] == '+')
		{
			BigInt bi = bi1 + bi2;
			OutPutList out_list;
			out_list.Add(bi1.ToString(), bi1.right_space_count());
			out_list.Add(string("+") + bi2.ToString(), bi2.right_space_count());
			out_list.Add(string(std::max(bi2.DisplayWidth() + 1, bi.DisplayWidth()), '-'), 0);
			out_list.Add(bi.ToString(), 0);
			out_list.OutPut();
			cout<<"\n";
		}
		else if(line[pos] == '-')
		{
			BigInt bi = bi1 - bi2;
			OutPutList out_list;
			out_list.Add(bi1.ToString(), 0);
			out_list.Add(string("-") + bi2.ToString(), 0);
			out_list.Add(string(std::max(bi2.DisplayWidth() + 1, bi.DisplayWidth()), '-'), 0);
			out_list.Add(bi.ToString(), 0);
			out_list.OutPut();
			cout<<"\n";
		}
		else if(line[pos] == '*')
		{
			OutPutList out_list;
			out_list.Add(bi1.ToString(), 0);
			out_list.Add(string("*") + bi2.ToString(), 0);
			BigInt total;
			total.FromString("0");
			size_t last_display_length = 0;
			for(int32_t i = 0; i < str2.length(); ++i)
			{
				int32_t v = str2[str2.length() - 1 -i] - '0';
				BigInt bi = bi1.Multiply(v, i);
				if(i == 0)
				{
					out_list.Add(string(std::max(bi.DisplayWidth(), bi2.DisplayWidth() + 1), '-'), 0);
				}
				if(i == str2.length() - 1)
				{
					last_display_length = bi.DisplayWidth();
				}
				string s = bi.ToString();
				out_list.Add(s, i);
				total = total + bi;

				//cout<<"======>"<<total.ToString()<<endl;
			}
			if(str2.length() > 1)
			{
				string s = total.ToString();
				out_list.Add(string(std::max(last_display_length, s.length()), '-'), 0);
				out_list.Add(s, 0);;
			}
			out_list.OutPut();
			cout<<"\n";
		}
	}
}
