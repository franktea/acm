/*
 * 127.cpp
 *
 *  Created on: Sep 19, 2018
 *      Author: frank
 */

#include <string>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// 先做126，直接把126的拿来改一下

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    	std::map<int, std::set<int>> edges; // key和value都是在wordList中的下标
    	// wordlist不包含开始单词，将其插入到数组的开头(有些case居然含有endword，好恶心，先找一下)
    	auto begin_it = std::find(wordList.begin(), wordList.end(), beginWord);
    	if(begin_it == wordList.end())
    	{
			wordList.push_back(beginWord);
			std::iter_swap(wordList.begin(), wordList.end()-1);
    	}
    	else
    	{
    		std::iter_swap(wordList.begin(), begin_it);
    	}

    	//先查找endword是否存在
    	auto it = std::find(wordList.begin(), wordList.end(), endWord);
    	if(it == wordList.end())
    		return 0;
    	std::iter_swap(it, wordList.end()-1); // 将endword放到最末尾

    	auto check = [&wordList](int i, int j)->bool {
    		const string& str1 = wordList[i];
    		const string& str2 = wordList[j];
    		if(str1.length() != str2.length())
    			return false;
    		int diff = 0;
    		for(int x = 0; x < str1.length(); ++x)
    		{
    			if(str1[x] != str2[x])
    				++diff;
    			if(diff > 1)
    				return false;
    		}

    		return 1 == diff;
    	};

    	//构建连接关系
    	for(int i = 0; i < wordList.size(); ++i)
    	{
    		for(int j = i+1; j < wordList.size(); ++j)
    		{
    			if(check(i, j))
    			{
    				edges[i].insert(j);
    				edges[j].insert(i);
    			}
    		}
    	}

    	const int end_index = wordList.size() - 1;

    	// 如果beginword或者endword没有任何邻结点，直接返回
		auto it1 = edges.find(0);
		if(it1 == edges.end() || it1->second.empty())
		{
			return 0;
		}
		auto it2 = edges.find(end_index);
		if(it2 == edges.end() || it2->second.empty())
		{
			return 0;
		}

    	std::vector<int> visited;
    	visited.resize(wordList.size(), 0);
    	struct BfsItem // bfs item, 也可以用std::pair,但是用struct意义会更明显
    	{
    		int level;
    		int index;
    	};
    	std::queue<BfsItem> bfs_queue;
    	visited[0] = 1;
    	bfs_queue.push({0, 0});

    	int end_level = std::numeric_limits<int>::max();
    	while(! bfs_queue.empty())
    	{
    		BfsItem bi = bfs_queue.front();
    		bfs_queue.pop();

    		auto it = edges.find(bi.index);
    		if(it == edges.end())
    			continue;
    		for(int son: it->second)
    		{
    			if(visited[son])
    			{
    				continue;
    			}
    			visited[son] = 1;
    			if(son == end_index)
    			{
    				return bi.level + 2;
    			}
    			bfs_queue.push({bi.level+1, son});
    		}
    	}

    	return 0;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	return 0;
}

