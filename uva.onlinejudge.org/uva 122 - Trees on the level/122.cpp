/*
 * 122.cpp
 * uva 122 - Trees on the level
 *  Created on: Apr 8, 2017
 *      Author: frank
 */

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <stdint.h>
#include <memory>
#include <sstream>
#include <regex>

using namespace std;

class Node
{
	friend class Tree;
public:
	Node(int32_t level = 0):level(level)
	{
		value = 0; // 题目说了全是正整数，为0就能表示未赋值
	}

	bool GetOutputByLevel(std::vector<std::list<int32_t>>& arr)
	{
		if(0 == value)
			return false;

		auto& l = arr[level];
		l.push_back(value);

		if(left)
		{
			if(! left->GetOutputByLevel(arr))
				return false;
		}

		if(right)
		{
			if(! right->GetOutputByLevel(arr))
				return false;
		}

		return true;
	}
private:
	int32_t value;
	int32_t level; // 记录每个节点的层次，这样就可以用深度优先的方法输出广度优先的结果了
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
};

class Tree
{
public:
	Tree()
	{
		root = std::shared_ptr<Node>(new Node);
		max_level_ = 0;
		multi_value_ = false;
	}
public:
	// dir_string is like: "LLR" "RRR" or ""
	// 如果需要添加的节点已经不是第一次添加，返回false
	void AddNode(int32_t value, const string& dir_string)
	{
		std::shared_ptr<Node> node =  root;
		if(dir_string == "") // 根节点
		{
			SetValue(root, value);
			return;
		}

		for(char c: dir_string)
		{
			node = FindNode(node, c);
		}
		SetValue(node, value);
	}

	void OutpuByLevel()
	{
		if(multi_value_)
		{
			cout<<"not complete\n";
			return;
		}

		std::vector<std::list<int32_t>> arr;
		arr.resize(max_level_+1);
		bool r = root->GetOutputByLevel(arr);
		if(! r)
			cout<<"not complete\n";
		else
		{
			bool first = true;
			for(auto& l: arr)
			{
				for(int32_t v: l)
				{
					if(first)
					{
						cout<<v;
						first = false;
					}
					else
					{
						cout<<" "<<v;
					}
				}
			}
			cout<<"\n";
		}
	}
private:
	// direction = 'L' or 'R'
	std::shared_ptr<Node> FindNode(shared_ptr<Node> node, char direction)
	{
		if(direction == 'L')
		{
			if(! node->left)
				node->left = std::shared_ptr<Node>(new Node(node->level+1));
			node = node->left;
		}
		else
		{
			if(! node->right)
				node->right = std::shared_ptr<Node>(new Node(node->level+1));
			node = node->right;
		}
		if(node->level > max_level_)
			max_level_ = node->level;
		return node;
	}

	void SetValue(shared_ptr<Node> node, int32_t value)
	{
		if(node->value != 0)
		{
			multi_value_ = true;
		}
		node->value = value;
	}

private:
	std::shared_ptr<Node> root;
	int32_t max_level_;
	bool multi_value_; // 如果某个节点被赋值多次，则为true
};

void Test()
{
	std::shared_ptr<Tree> tree = std::shared_ptr<Tree>(new Tree);
	tree->AddNode(11, "LL");
	tree->AddNode(7, "LLL");
	tree->AddNode(8, "R");
	tree->AddNode(5, "");
	tree->AddNode(4, "L");
	tree->AddNode(13, "RL");
	tree->AddNode(2, "LLR");
	tree->AddNode(1, "RRR");
	tree->AddNode(4, "RR");
	tree->OutpuByLevel();
}

int main()
{
	regex reg("\\((\\d+),(.*)\\)");
	std::shared_ptr<Tree> tree = shared_ptr<Tree>(new Tree);
	string token;
	while(cin>>token)
	{
		if(token == "()")
		{
			tree->OutpuByLevel();
			tree = shared_ptr<Tree>(new Tree);
		}
		else
		{
			smatch m;
			bool found = regex_search(token, m, reg);
			if(! found)
			{
				cout<<token<<" not found!\n";
			}
			else
			{
				//cout<<token<<"===>"<<m.str(1)<<","<<m.str(2)<<"\n";
				tree->AddNode(atoi(m.str(1).c_str()), m.str(2));
			}
		}
	}
	//Test();
	return 0;
}


