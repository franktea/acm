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

struct KeyPoint // 最终的结果，只需要x和height，但是由于有些点要合并，所以需要记住old height
{
	int x;
	int height;
	int old_height;
};

// 从左到右扫描，在上一个扫描的店未结束的区间，全部保存在这样一个数据结构中
class CurrentRanges
{
public:
	CurrentRanges(const vector<vector<int>>& buildings, vector<KeyPoint>& result):
		current_height_(0),
		current_index_(std::numeric_limits<size_t>::max()),
		buildings_(buildings),
		result_(result){}
public:
	void RangeBegin(size_t index) // met a new range
	{
		int new_x = buildings_[index][0];
		int new_height = buildings_[index][2];
		if(new_height > current_height_)
		{
			if(!result_.empty() && result_[result_.size() - 1].x == new_x) // 需要合并结果
			{
				//cout<<"=>"<<result_[result_.size() - 1].x<<","<<result_[result_.size() - 1].height<<","<<result_[result_.size() - 1].old_height<<"\n";
				int old_height = result_[result_.size() - 1].old_height;
				result_.erase(result_.end() - 1, result_.end());
				//cout<<"old_height: "<<old_height<<"\n";
				if(new_height != old_height)
				{
					result_.push_back({new_x, new_height, current_height_});
				}
			}
			else
			{
				result_.push_back({new_x, new_height, current_height_});
			}

			current_index_ = index;
			current_height_ = new_height;
		}
		range_heights_[new_height].insert(index);
	}

	void RangeEnd(size_t index) // some range ended
	{
		EraseIndex(index);
		if(buildings_[index][2] < current_height_)
		{
			return;
		}

		// ended_height == current_height_
		if(index == current_index_)
		{
//			if(!range_heights_.empty())
//			{
//				vector<size_t> index_to_remove; // 终点与当前终点相同的区间，全部删掉
//				for(auto it: range_heights_.begin()->second)
//				{
//					if(buildings_[it][1] == buildings_[index][1])
//						index_to_remove.push_back(it);
//				}
//				for(size_t i: index_to_remove)
//				{
//					EraseIndex(i);
//				}
//			}

			// 找到当前序列中最高的
			if(range_heights_.empty())
			{
				result_.push_back({buildings_[index][1], 0, current_height_});
				current_height_ = 0;
				current_index_ = std::numeric_limits<size_t>::max();
				return;
			}

			int new_height = range_heights_.begin()->first;
			current_index_ = *(range_heights_.begin()->second.begin());
			if(new_height != current_height_)
			{
				if(buildings_[index][1] != buildings_[current_index_][1])
				{
					result_.push_back({buildings_[index][1], new_height, current_height_});
					current_height_ = new_height;
				}
				else
				{
					result_.push_back({buildings_[index][1], 0, current_height_});
					current_height_ = new_height;
				}
			}
		}
	}
private:
	void EraseIndex(size_t index)
	{
		auto it = range_heights_.find(buildings_[index][2]);
		it->second.erase(index);
		if(it->second.empty())
		{
			range_heights_.erase(it);
		}
	}
private:
	int current_height_; // max height of all ranges now
	size_t current_index_;
	std::map<int, std::set<int>, std::greater<int>> range_heights_; // 已高度降序排列的range index
	const vector<vector<int>>& buildings_; // 所有排序过后的building
	vector<KeyPoint>& result_;
};

class Solution {
	struct XValue // 每个建筑物的起点终点的x坐标排序，然后从小到大扫描
	{
		int x;
		size_t index; // index in the sorted vector
		bool ending; // 是否终点
		bool operator<(const XValue& another) const
		{
			return (this->x < another.x) || (this->x == another.x && int(this->ending) > int(another.ending));
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
    		xvalues.push_back(XValue{buildings[i][0], i, false});
    		xvalues.push_back(XValue{buildings[i][1], i, true});
    	}
    	std::sort(xvalues.begin(), xvalues.end());

    	vector<KeyPoint> result;
    	CurrentRanges cr(buildings, result);
    	//for(const XValue& xv: xvalues)
    	for(size_t i = 0; i < xvalues.size(); ++i)
    	{
    		const XValue& xv = xvalues[i];
    		cout<<"point index = "<<xv.index;
    		if(xv.ending)
    		{
    			cr.RangeEnd(xv.index);
    			cout<<" ending, ";
    		}
    		else
    		{
    			cr.RangeBegin(xv.index);
    			cout<<" begin, ";
    		}
    		cout<<"x = "<<xv.x<<"\n";
    	}

    	vector<pair<int, int>> v;
    	for(const KeyPoint& kp: result)
    	{
    		v.push_back({kp.x, kp.height});
    	}
    	return v;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> buildings = // { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };
		//{ {0, 2, 3}, {2, 5, 3} };
		{{2, 4, 7}, {2, 4, 5}, {2, 4, 6}};
	auto&& v = s.getSkyline(buildings);
	for(const auto& p: v)
	{
		cout<<p.first<<", "<<p.second<<"\n";
	}

	return 0;
}
