/*902.cpp
frank May 6, 2018
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdint.h>

using namespace std;

void Solve(size_t len, const string& line)
{
	std::map<string, size_t> count_map; // substr and occurrence times
	for(size_t i = 0; i < line.size() - len + 1; ++i)
	{
		string sub = line.substr(i, len);
		++ count_map[sub];
	}


	auto it = std::max_element(count_map.begin(), count_map.end(), [](const std::pair<string, int>& lhs,
			const std::pair<string, int>& rhs)
			{
				return lhs.second < rhs.second;
			});

	cout<<it->first<<"\n";
}

int main()
{
	size_t len;
	string line;
	while(cin>>len>>line)
	{
		//cout<<len<<"==>"<<line<<"\n";
		Solve(len, line);
	}
	return 0;
}


