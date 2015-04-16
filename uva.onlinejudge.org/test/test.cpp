/*
 * test.cpp
 *
 *  Created on: Feb 22, 2015
 *      Author: frank
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdint.h>

using namespace std;

// 组合方式的遍历，解空间大小为2**N
void BackTrack(const vector<int32_t>&v, vector<int32_t>& result, int32_t level)
{
	if(level >= v.size() - 1)
	{
		for(size_t i = 0; i < result.size(); ++i)\
			if(result[i] == 1)
				cout<<v[i]<<", ";
		cout<<"\n";
		return;
	}

	for(int32_t i = 0; i <= 1; ++i)
	{
		result.resize(level+1);
		result[level] = i;
		BackTrack(v, result, level+1);
	}
}

void BackTrack2(const vector<int32_t>& v, vector<int32_t>& visited,
		vector<int32_t>& result, const int32_t level)
{
	if(level >= v.size())
	{
		for(size_t i = 0; i < result.size(); ++i)
		{
			cout<<result[i]<<", ";
		}
		cout<<"\n";
		return;
	}

	result.resize(level+1);
	for(size_t i = 0; i < v.size(); ++i)
	{
		if(! visited[i])
		{
			visited[i] = 1;
			result[level] = v[i];
			BackTrack2(v, visited, result, level+1);
			visited[i] = 0;
		}
	}
}

int main()
{
	vector<int32_t> v = {1, 2, 3, 4, 5};
	vector<int32_t> visited(v.size(), 0);
	vector<int32_t> result(v.size(), 0);
	//BackTrack(v, result, 0);
	BackTrack2(v, visited, result, 0);
	return 0;
}
