/*
 * uva 10324 - Zeros and Ones
 *
 *  Created on: Apr 22, 2018
 *      Author: frank
 */
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int case_count = 1;
	string line;
	while(std::getline(cin, line))
	{
		if(line.empty())
			break;

		cout<<"Case "<<case_count<<":\n";

		int pair_count;
		cin>>pair_count;
		if(pair_count <= 0)
			break;

		while(pair_count--)
		{
			int a, b;
			cin>>a>>b;
			if(a > b)
			{
				std::swap(a, b);
			}

			char v = line[a];
			bool same = true;
			for(int i = a; i <= b; ++i)
			{
				if(line[i] != v)
				{
					same = false;
					break;
				}
			}


			cout<< (same ? "Yes\n" : "No\n");
		}

		std::getline(cin, line); // 吃掉换行符
		++case_count;
	}
	return 0;
}



