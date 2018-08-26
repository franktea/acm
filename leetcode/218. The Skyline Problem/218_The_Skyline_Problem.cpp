/*
 * 218_The_Skyline_Problem.cpp
 *
 *  Created on: Aug 25, 2018
 *      Author: frank
 */

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
	struct XValue // 每个建筑物的起点终点的x坐标排序，然后从小到大扫描
	{
		int x;
		size_t index; // index in the sorted vector
		bool ending; // 是否终点
		bool operator<(const XValue& another) const
		{
			return this->x < another.x;
		}
	};
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
	{
    	// delete duplicate
    	buildings.erase(unique(buildings.begin(), buildings.end()), buildings.end());

    	std::vector<XValue> xvalues;
    	for(size_t i = 0; i < buildings.size(); ++i)
    	{
    		xvalues.emplace_back(XValue{buildings[i][0], i, false});
    		xvalues.emplace_back(XValue{buildings[i][1], i, true});
    	}
    }
};
