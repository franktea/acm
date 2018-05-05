/*12397.cpp
frank May 6, 2018
*/
#include <iostream>
#include <string>
#include <map>
#include <cctype> // isdigit, isalpha
#include <stdint.h>

using namespace std;

string Int2Roman(int number)
{
	string result;
	std::map<int, string> number_map = { {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"},
			{10, "X"}, {20, "XX"}, {30, "XXX"}, {40, "XL"}, {50, "L"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"},
			{100, "C"}, {200, "CC"}, {300, "CCC"}, {400, "CD"}, {500, "D"}, {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"},
			{1000, "M"}, {2000, "MM"}, {3000, "MMM"}};
	// 先求千位数
	int x = number / 1000;
	if(x > 0)
	{
		number %= 1000;
		x *= 1000;
		result.append(number_map[x]);
	}
	// 再求百位数
	x = number / 100;
	if(x > 0)
	{
		number %= 100;
		x *= 100;
		result.append(number_map[x]);
	}
	// 再求十位数
	x = number / 10;
	if(x > 0)
	{
		number %= 10;
		x *= 10;
		result.append(number_map[x]);
	}
	// 再求个位数
	if(number > 0)
	{
		result.append(number_map[number]);
	}

	return result;
}

int MatchCount(char c)
{
	//每个字母需要火柴的根数
	static std::map<char, int> count_map = {{'I', 1}, {'V', 2}, {'X', 2}, {'L', 2}, {'C', 2}, {'D', 3}, {'M', 4}};
	return count_map[c];
}

int main()
{
	int number;
	while(cin>>number)
	{
		string roman = Int2Roman(number);
		//cout<<"get: "<<roman<<"\n";
		int result = 0;
		for(char c : roman)
		{
			result += MatchCount(c);
		}
		cout<<result<<"\n";
	}

	return 0;
}

