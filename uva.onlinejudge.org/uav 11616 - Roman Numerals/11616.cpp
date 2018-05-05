/*11616.cpp
frank May 5, 2018
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

int Roman2Int(const string& roman)
{
	std::map<string, int> number_map = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9},
			{"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90},
			{"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900},
			{"M", 1000}};

	int result = 0;

	size_t index = 0;
	while(index < roman.length())
	{
		auto it = number_map.find(roman.substr(index, 2));
		if(it != number_map.end())
		{
			result += it->second;
			index += 2;
		}
		else
		{
			result += number_map[roman.substr(index, 1)];
			++index;
		}
	}
	return result;
}

int main()
{
	string line;
	while(std::getline(cin, line))
	{
		if(line.empty())
			break;

		if(std::isdigit(line[0]))
			cout<<Int2Roman(std::stoi(line))<<"\n";
		else
			cout<<Roman2Int(line)<<"\n";
	}

	return 0;
}


