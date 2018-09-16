/*
 * bit_field.h
 *
 *  Created on: Aug 31, 2018
 *      Author: frank
 */

#ifndef LEETCODE_773__SLIDING_PUZZLE_BIT_FIELD_H_
#define LEETCODE_773__SLIDING_PUZZLE_BIT_FIELD_H_

#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;


// 用位域来解，节省空间

// [[s00, s01, s02]
//  [s10, s11, s12]]
typedef struct
{
	int s00: 4;
	int s01: 4;
	int s02: 4;
	int s10: 4;
	int s11: 4;
	int s12: 4;
	int x0: 4; // x of the element 0, x belong [0, 1]
	int y0: 4; // y of the element 0, y belong [0, 2]
}BoardData;

class BoardStage
{
	typedef union
	{
		BoardData data;
		int value;
	}SlideField;
public:
	void Set(const vector<vector<int>>& init)
	{
		this->depth = 0;

		BoardData& data = fields.data;
		data.s00 = init[0][0];
		data.s01 = init[0][1];
		data.s02 = init[0][2];
		data.s10 = init[1][0];
		data.s11 = init[1][1];
		data.s12 = init[1][2];

		for(int x = 0; x < 2; ++x)
			for(int y = 0; y < 3; ++y)
				if(init[x][y] == 0)
				{
					data.x0 = x;
					data.y0 = y;
					break;
				}
	}

	int GetData(int x, int y)
	{
		const BoardData& data = fields.data;
		vector<vector<std::function<int()>>> fv = { {[&data](){ return data.s00; },
				[&data](){ return data.s01; },
				[&data](){ return data.s02; } },
				{[&data](){ return data.s10; },
				[&data](){ return data.s11; },
				[&data](){ return data.s12; } } };
		return fv[x][y]();
	}

	void SetData(int x, int y, int v)
	{
		BoardData& data = fields.data;
		vector<vector<std::function<void(int)>>> fv = { {[&data](int v){ data.s00 = v; },
				[&data](int v){ data.s01 = v; },
				[&data](int v){ data.s02 = v; } },
				{[&data](int v){ data.s10 = v; },
				[&data](int v){ data.s11 = v; },
				[&data](int v){ data.s12 = v; } } };
		fv[x][y](v);
	}

	int Value() const
	{
		return fields.value;
	}

	bool IsTarget() const
	{
		static const BoardData target = {1, 2, 3, 4, 5, 0, 1, 2};
		return 0 == memcmp(&(this->fields.data), &target, sizeof(BoardData));
	}

	int Depth() const
	{
		return depth;
	}

	BoardStage Child(int direction) // 0 <= direction < 4
	{
		BoardStage result;
		result.fields.value = 0;
		if(direction < 0 || direction >= 4)
		{
			return result;
		}

		const int delta_x[] = {1, 0, -1, 0};
		const int delta_y[] = {0, -1, 0, 1};

		const BoardData& data = fields.data;
		const int x = data.x0 + delta_x[direction];
		const int y = data.y0 + delta_y[direction];
		if(x < 0 || x >= 2 || y < 0 || y >= 3)
		{
			return result;
		}

		result = *this;
		result.depth = this->depth + 1;
		BoardData& child_data = result.fields.data;
		result.SetData(data.x0, data.y0, result.GetData(x, y));
		result.SetData(x, y, 0);
		child_data.x0 = x;
		child_data.y0 = y;
		return result;
	}
private:
	SlideField fields;
	int depth;
};

class Solution
{
public:
    int slidingPuzzle(vector<vector<int>>& board)
    {
    	BoardStage root;
    	root.Set(board);

    	std::unordered_set<int> visited;
    	std::queue<BoardStage> unvisited; // as a queue 为什么这里用list就不行了？用list是一个错误的队列，貌似不是先进先出
    	unvisited.push(root);
    	visited.insert(root.Value());

    	while(! unvisited.empty())
    	{
    		BoardStage& head = unvisited.front();
    		unvisited.pop();

    		//cout<<head.Value()<<"\n";

    		if(head.IsTarget())
    		{
    			return head.Depth();
    		}

    		for(int direction = 0; direction < 4; ++ direction)
    		{
    			BoardStage child = head.Child(direction);
    			if(child.Value() && (visited.find(child.Value()) == visited.end()))
    			{
    				unvisited.push(child);
    				visited.insert(child.Value());
    			}
    		}
    	}

    	return -1;
    }
};

#endif /* LEETCODE_773__SLIDING_PUZZLE_BIT_FIELD_H_ */
