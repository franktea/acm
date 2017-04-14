/*
 * 1588.cpp
 *	uva 1588 - Kickdown
 *  Created on: Apr 14, 2017
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

size_t Check(const string& btm, const string& top)
{
	//cout<<"checking:"<<btm<<","<<top<<"\n";
	auto sub_check = [&btm, &top](const size_t index)->size_t
		{
			for(size_t i = 0; i < top.size() && i + index < btm.size(); ++i)
			{
				if( (top[i] - '0') + (btm[i+index] - '0') > 3)
					return false;
			}

			return true;
		};

	size_t result = btm.size() + top.size();
	for(size_t index = 0; index < btm.size(); ++index)
	{
		if(sub_check(index))
		{
			//cout<<"index="<<index<<"\n";
			const size_t len = btm.size() - index;
			if(len >= top.size())
			{
				result = btm.size();
			}
			else
			{
				result = top.size() - len + btm.size();
			}
			break;
		}
	}

	return result;
}

int main()
{
	string bottom, top;
	while(cin>>bottom>>top)
	{
		cout<<std::min(Check(bottom, top), Check(top, bottom))<<"\n";
	}
	return 0;
}



