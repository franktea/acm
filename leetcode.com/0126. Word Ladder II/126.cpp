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

// 所有单词构成无向图。其实是在无向图中找出所有最短路径。
// 如果只是找一条最短路径，可以用bfs。找全部的也可以用bfs，就是在找到第一条路径的时候，记住当前的level，不要停下来，继续找，
// 知道当前level的节点遍历完毕为止。
// 有一个需要注意的问题，在遍历节点时，如果展开碰到曾经遍历过的节点，且该节点为的level为当前节点的level+1，表示当前节点也是一条新的最短路径。
// 典型的case：
// begin = red, end = tax, wordlist=[red, ted, rex, tex, tad, tax]

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

    	const int end_index = wordList.size() - 1;

    	// 如果beginword或者endword没有任何邻结点，直接返回
		auto it1 = edges.find(0);
		if(it1 == edges.end() || it1->second.empty())
		{
			return ret;
		}
		auto it2 = edges.find(end_index);
		if(it2 == edges.end() || it2->second.empty())
		{
			return ret;
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

    	//key->value存的是每个单词在遍历时的父节点下标，找到结果时根据这个结果可以还原出路径，
    	//本解法不含起始节点，因为起始节点的index是0
    	std::map<int, PathItem> path;
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
    				if(path[son].level == bi.level+1)
    				{
    					path[son].parents.push_back(bi.index);
    				}

    				continue;
    			}
    			visited[son] = 1;
    			path[son] = PathItem{bi.level+1, std::vector<int>{bi.index}};
    			if(son == end_index)
    			{
    				end_level = bi.level;
    			}
    			bfs_queue.push({bi.level+1, son});
    		}
    	}

    	points.push_back(end_index);
    	DFS(end_index, path, wordList, ret);

    	return ret;
    }
private:
	struct PathItem
	{
		int level;
		vector<int> parents;
	};
	vector<int> points;
    void DFS(int index, std::map<int, PathItem>& path, vector<string>& words, vector<vector<string>>& result)
    {
    	if(0 == index) // output
    	{
    		vector<string> v;
    		for(auto it = points.rbegin(); it != points.rend(); ++it)
    		{
    			v.push_back(words[*it]);
    		}
    		result.push_back(v);
    		return;
    	}

    	auto it = path.find(index);
    	for(int v: it->second.parents)
    	{
    		points.push_back(v);
    		DFS(v, path, words, result);
    		points.pop_back();
    	}
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
//	string begin_word = "red";
//	string end_word = "tax";
//	vector<string> words = {"ted","tex","red","tax","tad","den","rex","pee"};
	string begin_word = "hot";
	string end_word = "dog";
	vector<string> words = {"hot", "dog"};
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



