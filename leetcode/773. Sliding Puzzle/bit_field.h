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
#include <list>
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

	int Value() const
	{
		return fields.value;
	}
private:
	SlideField fields;
};


#endif /* LEETCODE_773__SLIDING_PUZZLE_BIT_FIELD_H_ */
