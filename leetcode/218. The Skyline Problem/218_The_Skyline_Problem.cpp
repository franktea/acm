/*
 * 218_The_Skyline_Problem.cpp
 *
 *  Created on: Aug 25, 2018
 *      Author: frank
 */

#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>
#include <limits>

using namespace std;

// 从左到右每一个点，排序后逐个扫描。
struct XPoint
{
	int x;
	vector<int> begin_ids; // begin range ids，id就是在某个range在原始数组中的下标
	vector<int> end_ids; // end range ids
};

// 从左到右扫描每个点（包括起始点和结束点），没扫到一个点，将当前有效区间保存起来
class ScanResult
{
public:
	ScanResult(const vector<XPoint>& sorted_points, const vector<vector<int>>& buildings):
		sorted_points_(sorted_points), buildings_(buildings) {}

	void Scan(vector<pair<int, int>>& result) // result是返回的结果
	{
		int current_height = 0;
		int current_id = -1;
		for(const XPoint& point: sorted_points_)
		{
			if(! point.end_ids.empty())
			{
				if(! point.begin_ids.empty()) // begin && end，既是某些区间的起点，又是某些区间的终点
				{
					for(int id: point.end_ids)
					{
						EraseId(id);
					}

					const int height = buildings_[point.begin_ids[0]][2];
					if(ranges_.empty() && height != current_height)
					{
						result.push_back({point.x, height});
						current_height = height;
						current_id = point.begin_ids[0];
					}
					else if(height > current_height)
					{
						result.push_back({point.x, height});
						current_height = height;
						current_id = point.begin_ids[0];
					}

					for(int id: point.begin_ids)
					{
						const int h = buildings_[id][2];
						ranges_[h].insert(id);
					}
				}
				else // only end，仅仅是某些区间的终点，不是任何区间的起点
				{
					for(int id: point.end_ids)
					{
						EraseId(id);
					}

					if(ranges_.empty())
					{
						current_height = 0;
						current_id = -1;
						result.push_back({point.x, 0});
					}
					else
					{
						const int h = ranges_.begin()->first;
						if(current_height != h)
						{
							result.push_back({point.x, h});
							current_height = h;
							current_id = * (ranges_.begin()->second.begin());
						}
					}
				}
			}
			else // only begin，仅仅是某些区间的起点，不是任何区间的终点
			{
				int height = buildings_[point.begin_ids[0]][2];
				if(height > current_height)
				{
					result.push_back({point.x, height});
					current_height = height;
					current_id = point.begin_ids[0];
				}

				for(int id: point.begin_ids)
				{
					const int h = buildings_[id][2];
					ranges_[h].insert(id);
				}
			}
		}
	}
private:
	void EraseId(int id)
	{
		int h = buildings_[id][2];
		ranges_[h].erase(id);
		if(ranges_[h].empty())
		{
			ranges_.erase(h);
		}
	}
private:
	map<int, set<int>, std::greater<int>> ranges_; // height->ids
	const vector<XPoint>& sorted_points_;
	const vector<vector<int>>& buildings_;
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
	{
    	map<int, XPoint> point_map;
    	for(int i = 0; i < buildings.size(); ++i)
    	{
    		int x1 = buildings[i][0];
    		int x2 = buildings[i][1];
    		point_map[x1].x = x1;
    		point_map[x1].begin_ids.push_back(i);
    		point_map[x2].x = x2;
    		point_map[x2].end_ids.push_back(i);
    	}

    	// sort id by height
    	auto f = [&buildings](const int lhs, const int rhs) {
    		return buildings[lhs][2] > buildings[rhs][2];
		};

    	vector<XPoint> sorted_points;
    	sorted_points.reserve(point_map.size());
    	for(auto it: point_map)
    	{
    		XPoint& p = it.second;
    		sort(p.begin_ids.begin(), p.begin_ids.end(), f);
    		sort(p.end_ids.begin(), p.end_ids.end(), f);
    		sorted_points.push_back(p);
    	}

    	ScanResult sr(sorted_points, buildings);

    	vector<pair<int, int>> result;
    	sr.Scan(result);
    	return result;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> buildings = // { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };
		{ {0, 2, 3}, {2, 5, 3} };
		 //{{2, 4, 7}, {2, 4, 5}, {2, 4, 6}};
		//{{2, 4, 70}, {3,8,30}, {6,100,41},{7,15,70},{10,30,102},{15,25,76},{60,80,91},{70,90,72},{85,120,59}};
		//{{0, 5, 7}, {5, 10, 7}, {5, 10, 12}, {10, 15, 7}, {15, 20, 7}, {15,20, 12}, {20, 25, 7}};
	auto&& v = s.getSkyline(buildings);
	for(const auto& p: v)
	{
		cout<<p.first<<", "<<p.second<<"\n";
	}

	return 0;
}
