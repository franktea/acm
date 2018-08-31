/*
 * 773_Sliding_Puzzle.cpp
 *
 *  Created on: Aug 31, 2018
 *      Author: frank
 */
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_set>
#include <list> // as stack
#include <algorithm>
#include <queue>

using namespace std;

// 广度优先

// 四个方向
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

const char dest[][3] = { {1, 2, 3}, {4, 5, 0}};

struct Node
{
	int depth; // 树的第几层，如果得到最终解，也即需要输出的步数
	char arr[2][3];
	int x_0; // x pos of item 0
	int y_0;

	Node(int d, const vector<vector<int>>& board)
	{
		depth = d;
		for(int x = 0; x < 2; ++x)
			for(int y = 0; y < 3; ++y)
				arr[x][y] = char(board[x][y]);

		FindZero();
	}

	Node(const Node& another)
	{
		this->depth = another.depth;
		//memcpy(this->arr, another.arr, sizeof(this->arr));
		for(int x = 0; x < 2; ++x)
			for(int y = 0; y < 3; ++y)
				arr[x][y] = another.arr[x][y];
		this->x_0 = another.x_0;
		this->y_0 = another.y_0;
	}

	void FindZero()
	{
		for(int x = 0; x < 2; ++x)
			for(int y = 0; y < 3; ++y)
				if(arr[x][y] == 0)
				{
					x_0 = x;
					y_0 = y;
					return;
				}
	}

	string ToString() const
	{
		string result = std::to_string(depth) + ",";
		for(int x = 0; x < 2; ++x)
			for(int y = 0; y < 3; ++y)
				result.append(std::to_string(int(arr[x][y])));
		result.push_back('_');
		result.append(std::to_string(int(x_0)) + "," + std::to_string(int(y_0)));
		return result;
	}

	bool Check()
	{
		return 0 == memcmp(arr, dest, sizeof(dest));
	}

	void MoveTo(int x, int y)
	{
		arr[x_0][y_0] = arr[x][y];
		arr[x][y] = 0;
		x_0 = x;
		y_0 = y;
	}

	string Key() const
	{
		string result;
		for(int x = 0; x < 2; ++x)
			for(int y = 0; y < 3; ++y)
				result.append(std::to_string(int(arr[x][y])));
		//return string(&arr[0][0], &arr[1][3]);
		return result;
	}

	// enqueue unvisited children into a queue
	void EnqueueChildren(queue<Node>& q, unordered_set<string>& visited) const
	{
		for(int i = 0;i < 4; ++i)
		{
			const int x = x_0 + dx[i];
			const int y = y_0 + dy[i];
			//cout<<this->ToString()<<"=====>"<<dx[i]<<", "<<dy[i]<<":::::"<<x<<","<<y<<"\n";

			if(x >= 0 && x < 2 && y >= 0 && y < 3)
			{
				Node temp_node = *this;
				temp_node.depth = this->depth + 1;
				temp_node.MoveTo(x, y);

				//cout<<":::::::::::::"<<this->ToString()<<"\n";
				//cout<<"::::::::temp:"<<temp_node.ToString()<<"\n";

				const string key = temp_node.Key();
				if(visited.find(key) ==  visited.end())
				{
					//cout<<"1111111111111"<<this->ToString()<<"\n";
					q.push(temp_node);
					//cout<<"2222222222222"<<this->ToString()<<"\n";
					visited.insert(key);
					//cout<<"3333333333333"<<this->ToString()<<"\n";
				}

				//cout<<",,,,,,,,,,,,,"<<this->ToString()<<"\n";
			}
		}
	}
};


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board)
    {
    	Node root(0, board);

    	unordered_set<string> visited; // key of visited nodes

    	queue<Node> nodes; // 此处改成list会出现莫名其妙的错误
    	nodes.push(root);
    	visited.insert(root.Key());

    	while(! nodes.empty())
    	{
    		Node& node = nodes.front();
    		nodes.pop();

    		cout<<"------------------------------processing: "<<node.ToString()<<"\n";

    		if(node.Check())
    			return node.depth;

    		node.EnqueueChildren(nodes, visited);
    	}

    	return -1;
    }
};

int main()
{
	Solution* ps = new Solution;
	vector<vector<int>> board = //{{1, 2, 3}, {4, 0, 5}};
		//{{4, 1, 2}, {5, 0, 3}};
		//{{3, 2, 4}, {1, 5, 0}};
		{{3,0,5},{4,2,1}};
	int ret = ps->slidingPuzzle(board);
	cout<<"ret="<<ret<<"\n";
	return 0;
}


