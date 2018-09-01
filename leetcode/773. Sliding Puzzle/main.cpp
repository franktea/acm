/*
 * main.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: frank
 */


#include <iostream>
#include "bit_field.h"

using namespace std;

int main()
{
	Solution* ps = new Solution;
	vector<vector<int>> board =// {{1, 2, 3}, {4, 0, 5}};
		//{{4, 1, 2}, {5, 0, 3}};
		//{{3, 2, 4}, {1, 5, 0}};
		// {{3,0,5},{4,2,1}};
		{{1, 2, 3}, {5, 4, 0}};
	int ret = ps->slidingPuzzle(board);
	cout<<"ret="<<ret<<"\n";
	return 0;
}
