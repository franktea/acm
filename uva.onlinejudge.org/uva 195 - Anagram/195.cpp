/*
 * 195.cpp
 *
 *  UVa 195 - Anagram
 *
 *  Created on: Feb 17, 2015
 *      Author: frank
 */

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <stddef.h>
#include <string>

using namespace std;

// 还是尝试使用方便的std::next_permutation算法，和146一样。
// 是字典序，不是ASCII序，AaBb...
struct Cmp
{
	bool operator()(const char& a, const char& b) const
	{
		if(tolower(a) == tolower(b))
		{
			return a < b;
		}

		return tolower(a) < tolower(b);
	}
};

void Next(string& line)
{
	Cmp cmp;
	cout<<line<<"\n";
    while(next_permutation(line.begin(), line.end(), cmp))
    {
        cout<<line<<"\n";
    }
}

int main()
{
	int32_t n;
	cin>>n;
	string line;
	while(n--)
	{
		cin>>line;
		//cout<<n<<"===="<<endl;
		//std::getline(cin, line);
		std::sort(line.begin(), line.end(), Cmp());
		Next(line);
	}
	return 0;
}

