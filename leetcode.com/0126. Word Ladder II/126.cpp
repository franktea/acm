/*
 * 126.cpp
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

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    	vector<vector<string>> ret;
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
    		return ret;
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

//    	for(auto&& s: wordList)
//    	{
//    		cout<<s<<", ";
//    	}
//    	cout<<"\n";
//
//    	for(auto&& it: edges)
//    	{
//    		cout<<it.first<<": ";
//    		for(int i: it.second)
//    			cout<<i<<", ";
//    		cout<<"\n";
//    	}

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
    	//key->value存的是每个单词在遍历时的父节点下标，找到结果时根据这个结果可以还原出路径，
    	//本解法不含起始节点，因为起始节点的index是0
    	std::map<int, int> path;
    	const int end_index = wordList.size() - 1;
    	std::vector<int> end_parents;
    	int end_level = std::numeric_limits<int>::max();
    	while(! bfs_queue.empty())
    	{
    		BfsItem bi = bfs_queue.front();
    		bfs_queue.pop();
    		if(bi.level > end_level)
    			break;

    		auto it = edges.find(bi.index);
    		if(it == edges.end())
    			continue;
    		for(int son: it->second)
    		{
    			if(visited[son])
    			{
    				if(son == end_index)
    					end_parents.push_back(bi.index);

    				continue;
    			}
    			visited[son] = 1;
    			path[son] = bi.index;
    			if(son == end_index)
    			{
    				end_parents.push_back(bi.index);
    				end_level = bi.level;
    			}
    			bfs_queue.push({bi.level+1, son});
    		}
    	}

//    	cout<<"end parents:";
//    	for(int i: end_parents)
//    		cout<<i<<", ";
//    	cout<<"\n";
//
//    	for(auto it: path)
//    		cout<<it.first<<"->"<<it.second<<"\n";

    	for(int v: end_parents) // 如果路径找到，end_parents包含了endword所有最短路径的父节点
    	{
    		vector<string> word_path;
    		word_path.push_back(wordList.back());// add endword
    		word_path.push_back(wordList[v]);
    		while(v)
    		{
    			v=path[v];
    			word_path.push_back(wordList[v]);
    		}
    		std::reverse(word_path.begin(), word_path.end());
    		ret.push_back(word_path);
    	}

    	return ret;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	string begin_word = "red";
	string end_word = "tax";
	vector<string> words = {"ted","tex","red","tax","tad","den","rex","pee"};
	auto&& ret = ps->findLadders(begin_word, end_word, words);
	for(auto&& v: ret)
	{
		cout<<"[";
		for(auto&& w: v)
			cout<<w<<", ";
		cout<<"]";
		cout<<"\n";
	}
	return 0;
}



