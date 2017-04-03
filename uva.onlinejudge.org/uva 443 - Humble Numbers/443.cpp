/**
 * uva 443 - Humble Numbers
 *
 * 果然还是STL强大，python没做出来
 *
 * frank 2017-04-03
 */
#include <iostream>
#include <set>
#include <vector>
#include <stdint.h>

using namespace std;

int main()
{
	std::vector<uint64_t> result;
	result.reserve(5842);
	std::set<uint64_t> occurrenced = {1};
	uint64_t count = 1;
	uint64_t number = 0;

	auto next = [&occurrenced](uint64_t number) -> uint64_t
		{
			if(0 == number)
				return 1;

			auto it = occurrenced.find(number);
			++it;
			return *it;
		};

	int64_t prims[] = {2, 3, 5, 7};
	while(result.size() < 5842)
	{
		number = next(number);
		result.push_back(number);
		for(auto c: prims)
		{
			uint64_t number2 = number * c;
			occurrenced.insert(number2);
		}
	}

	const char* suffix[] = {"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th"};
	auto get_suffix = [&suffix](uint64_t index) -> const char*
		{
			int64_t remainder_100 = index % 100;
			if(remainder_100 == 11 || remainder_100 == 12 || remainder_100 == 13)
				return suffix[0];

			return suffix[index % 10];
		};

	int64_t index;
	while(cin>>index)
	{
		if(0 == index)
			break;

		cout<<"The "<<index<<get_suffix(index)<<" humble number is "<<result[index-1]<<".\n";
	}

	return 0;
}
