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
#include <set>

using namespace std;

// 对于输入{{3,0,5},{4,2,1}};
// gcc的结果不对，但是clang是对的，原因未知!

// 广度优先

// 四个方向
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

const char dest[][3] = { {1, 2, 3}, {4, 5, 0}};

class Node
{
public:
	Node()
	{
		memset(this, 0, sizeof(Node));
	}

	void Set(const vector<vector<int>>& board)
	{
		depth_ = 0;
		for(int x = 0; x < 2; ++x)
			for(int y = 0; y < 3; ++y)
			{
				data_[x][y] = char(board[x][y]);
				if(data_[x][y] == 0)
				{
					x0_ = x;
					y0_ = y;
				}
			}
	}

	string Key() const
	{
		//return string(&data_[0][0], &data_[0][0] + 6);
		string result;
		for(int x = 0; x < 2; ++x)
			for(int y = 0; y < 3; ++y)
				result.append(std::to_string(int(data_[x][y])));
		return result;
	}

	bool IsTarget()
	{
		return 0 == memcmp(data_, dest, sizeof(dest));
	}

	Node Child(int direction)
	{
		Node child;
		int x = x0_ + dx[direction];
		int y = y0_ + dy[direction];
		if(x < 0 || x >= 2 || y < 0 || y >= 3)
		{
			return child;
		}

		child = *this;
		++child.depth_;
		std::swap(child.data_[x0_][y0_], child.data_[x][y]);
		child.x0_ = x;
		child.y0_ = y;

		return child;
	}

	int Depth() const
	{
		return depth_;
	}

	bool InValid() const
	{
		static const char uninited[2][3] = {{0, 0, 0}, {0, 0, 0}};
		return 0 == memcmp(data_, uninited, sizeof(data_));
	}
private:
	char data_[2][3];
	int depth_;
	int x0_;
	int y0_;
};


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board)
    {
    	Node root;
    	root.Set(board);

    	std::queue<Node> unvisited;
    	std::set<string> visited;

    	unvisited.push(root);
    	visited.insert(root.Key());

    	while(! unvisited.empty())
    	{
    		Node& head = unvisited.front();
    		unvisited.pop();

    		cout<<head.Key()<<"\n";

    		if(head.IsTarget())
    			return head.Depth();

    		for(int direction = 0; direction < 4; ++direction)
    		{
    			Node child = head.Child(direction);
    			if(child.InValid())
    				continue;

    			const string key = child.Key();
    			if(visited.find(key) != visited.end())
    				continue;

    			unvisited.push(child);
    			visited.insert(key);
    			cout<<"adding:"<<key<<"\n";
    		}
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
		//{{1, 2, 3}, {5, 4, 0}};
	int ret = ps->slidingPuzzle(board);
	cout<<"ret="<<ret<<"\n";
	return 0;
}


