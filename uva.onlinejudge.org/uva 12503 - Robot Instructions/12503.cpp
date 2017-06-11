/*
 * 12503.cpp
 *
 *  Created on: Jun 11, 2017
 *      Author: frank
 */
#include <functional>
#include <vector>
#include <iostream>
#include <string>
#include <stdint.h>
#include <cstdlib>

using namespace std;

class Moves
{
public:
	Moves(int32_t lines):count_(lines), value_(0){}
	void Input()
	{
		for(int32_t i = 0;i < count_; ++i)
		{
			string line;
			cin>>line;
			if(line == "LEFT")
			{
				--value_;
				instructions_.push_back([](int32_t& value)
						{
							--value;
						});
			}
			else if(line == "RIGHT")
			{
				++value_;
				instructions_.push_back([](int32_t& value)
						{
							++value;
						});
			}
			else // same as xxx
			{
				string as;
				string index;
				cin>>as>>index;
				int32_t step = std::atoi(index.c_str());
				instructions_[step-1](value_);
				instructions_.push_back(instructions_[step-1]);
			}
		}
	}

	void OutPut()
	{
		cout<<value_<<"\n";
	}
private:
	vector<std::function<void(int32_t&)>> instructions_;
	const int32_t count_;
	int32_t value_;
};

int main()
{
	int32_t cases;
	cin>>cases;
	while(cases--)
	{
		int32_t lines;
		cin>>lines;
		Moves m(lines);
		m.Input();
		m.OutPut();
	}
	return 0;
}



