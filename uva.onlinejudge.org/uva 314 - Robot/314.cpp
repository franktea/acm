/*
 * 314.cpp
 *
 *  uva 314 - Robot (dfs)
 *
 *  Created on: Mar 1, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <limits>
#include <algorithm>
#include <string>
#include <stdint.h>
#include <cassert>

using namespace std;

/**
 * dfs实现，tle了好几次，终于想到了一个ac的剪枝方法。网上搜到别人的都是bfs的，
 * 能用dfs解决这个问题也挺有意思。
 */

// 这样排序用异或运算就可以求得任意两个方向的转向次数
enum Direction { north = 0, west, east, south};
inline int32_t DirectionSeconds(Direction d1, Direction d2)
{
	return (bitset<2>(d1) ^ bitset<2>(d2)).count();
}

Direction GetDirection(std::string d)
{
	if(d == "east") return east;
	if(d == "west") return west;
	if(d == "north") return north;

	return south;
}

/**
 * 定义一个结构体，记录每个节点上一次被遍历时所用到的时间和对应的方向，
 * 用来作为dfs的剪枝。下一次再来到这个节点时，如果新的时间（比之前记录的时间 - 需要转向的时间）更大，
 * 则不用再遍历下去了。
 */
struct PosData
{
    int32_t t;
    Direction d;
};

void TestDirection()
{
	assert(DirectionSeconds(north, west) == 1);
	assert(DirectionSeconds(north, south) == 2);
	assert(DirectionSeconds(north, east) == 1);
	assert(DirectionSeconds(east, south) == 1);
	assert(DirectionSeconds(west, south) == 1);
	assert(DirectionSeconds(east, west) == 2);
	assert(DirectionSeconds(north, north) == 0);

	assert(GetDirection("east") == east);
	assert(GetDirection("west") == west);
	assert(GetDirection("south") == south);
	assert(GetDirection("north") == north);
}

void TestMap();

struct Position
{
	int32_t x;
	int32_t y;
	Direction d;
	Position operator+(const Position& p2)
	{
		return Position{x+p2.x, y+p2.y, p2.d};
	}
};

// 可以朝4个方向移动，每次可以移动1、2、3格，共有12种需要尝试
const vector<Position> near_by = { {-3, 0, north}, {-2, 0, north}, {-1, 0, north},
		{0, -3, west}, {0, -2, west}, {0, -1, west},
		{3, 0, south}, {2, 0, south}, {1, 0, south},
		{0, 3, east}, {0, 2, east}, {0, 1, east} };

class Map
{
	friend void TestMap();
public:
	Map(int32_t m, int32_t n): M_(m), N_(n), start_x_(0), start_y_(0), start_d_(north),
		end_x_(0), end_y_(0), min_time_(std::numeric_limits<int32_t>::max())
	{
		map_data_.resize(M_*N_);
		visited_.resize(M_*N_);
		pos_datas_.resize(M_*N_);
//		for(int32_t x = 0; x < M_; ++x)
//			for(int32_t y = 0; y < N_; ++y)
//			{
//				Value(x, y) = 0;
//				Visited(x, y) = 0;
//			}
	}

	void SetStartEnd(int32_t start_x, int32_t start_y, Direction start_d,
			int32_t end_x, int32_t end_y)
	{
		start_x_ = start_x;
		start_y_ = start_y;
		start_d_ = start_d;
		end_x_ = end_x;
		end_y_ = end_y;
	}

	void FindPath()
	{
		if(! CanGo(start_x_, start_y_) || ! CanGo(end_x_, end_y_))
		{
			cout<<"-1\n";
			return;
		}

		Position start_pos = {start_x_, start_y_, start_d_};
		int32_t total_time = 0;
		Visited(start_x_, start_y_) = 1;
		//Level(start_x_, start_y_) = 1;
		Find(start_pos, total_time, 1);
		if(min_time_ < std::numeric_limits<int32_t>::max())
			cout<<min_time_<<"\n";
		else
			cout<<"-1\n";
	}

	char& Value(int32_t x, int32_t y)
	{
		return map_data_[N_*x + y];
	}

	void Print()
	{
		for(int32_t x = 0; x < M_; ++x)
		{
			for(int32_t y = 0; y < N_; ++y)
			{
				cout<<int(Value(x, y))<<" ";
			}
			cout<<"\n";
		}
	}

	void PrintVisited()
	{
		for(int32_t x = 0; x < M_; ++x)
		{
			for(int32_t y = 0; y < N_; ++y)
			{
				cout<<int(Visited(x, y))<<" ";
			}
			cout<<"\n";
		}
	}
private:
	char& Visited(int32_t x, int32_t y)
	{
		return visited_[N_*x + y];
	}

	PosData& PosDatas(int32_t x, int32_t y)
	{
	    return pos_datas_[N_*x + y];
	}

	bool CanGoFromTo(const Position& pos1, const Position& pos2)
	{
		if(pos1.x == pos2.x)
		{
			if(pos2.y < pos1.y)
			{
				for(int32_t yy = pos2.y; yy < pos1.y; ++yy)
				{
					if(Visited(pos1.x, yy) || !CanGo(pos1.x, yy)) return false;
				}
			}
			else
			{
				for(int32_t yy = pos1.y+1; yy <= pos2.y; ++yy)
				{
					if(Visited(pos1.x, yy) || !CanGo(pos1.x, yy)) return false;
				}
			}
		}
		else if(pos1.y == pos2.y)
		{
			if(pos2.x < pos1.x)
			{
				for(int32_t xx = pos2.x; xx < pos1.x; ++xx)
				{
					if(Visited(xx, pos1.y) || !CanGo(xx, pos1.y)) return false;
				}
			}
			else
			{
				for(int32_t xx = pos1.x+1; xx <= pos2.x; ++xx)
				{
					if(Visited(xx, pos1.y) || !CanGo(xx, pos1.y)) return false;
				}
			}
		}

		return true;
	}

	bool CanGo(int32_t x, int32_t y)
	{
		return (x-1) >= 0 && (x-1) < M_ &&
				(y-1) >= 0 && (y-1) < N_ &&
				x >= 0 && x < M_ &&
				y >= 0 && y < N_ &&
				!(Value(x-1, y-1)||Value(x-1, y)||Value(x, y-1)||Value(x, y));
	}

	void Find(Position current_pos, int32_t current_time, int32_t level)
	{
		if(current_time >= min_time_) return;

		PosData& pd = PosDatas(current_pos.x, current_pos.y);
		if(pd.t != 0 && pd.t <= (current_time - DirectionSeconds(pd.d, current_pos.d)) )
		    return;
		pd.t = current_time;
		pd.d = current_pos.d;

		//cout<<"visit x="<<current_pos.x<<", y="<<current_pos.y<<"\n";
		if(current_pos.x == end_x_ && current_pos.y == end_y_)
		{
			min_time_ = current_time;
			//cout<<"FOUND!!!!!!!! time="<<current_time<<endl;
			//PrintVisited();
			return;
		}

		for(size_t i = 0; i < near_by.size(); ++i)
		{
			Position next_pos = current_pos + near_by[i];
			if(!CanGoFromTo(current_pos, next_pos)) continue;

			Visited(next_pos.x, next_pos.y) = 1;
			Find(next_pos, current_time + 1 + DirectionSeconds(current_pos.d, next_pos.d), level+1);
			Visited(next_pos.x, next_pos.y) = 0;
		}
	}
private:
	const int32_t M_;
	const int32_t N_;
	int32_t start_x_;
	int32_t start_y_;
	Direction start_d_;
	int32_t end_x_;
	int32_t end_y_;
	int32_t min_time_; //最短时间，运行时需要存起来，放在这里
	vector<char> map_data_;
	vector<char> visited_; // 每个节点在当前dfs栈空间里面是否被遍历过
	vector<PosData> pos_datas_; // 每个节点上一次被遍历时的状态数据
};

void TestMap()
{
	Map mp(10, 9);
	assert(mp.map_data_.size()==10*9);
	assert(mp.visited_.size()==10*9);
	for(int32_t x = 0; x < mp.M_; ++x)
		for(int32_t y = 0; y < mp.N_; ++y)
		{
			assert(mp.map_data_[x*9+y] == 0);
			assert(mp.visited_[x*9+y] == 0);
		}
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

//	TestDirection();
//	TestMap();
//	return 0;

	int32_t M, N;
	while(cin>>M>>N)
	{
		if(M == 0 && N == 0) break;
		Map mpp(M, N);
		for(int32_t x = 0; x < M; ++x)
		{
			for(int32_t y = 0; y < N; ++y)
			{
				int32_t data;
				cin>>data;
				mpp.Value(x, y) = data;
			}
		}
		int32_t sx, sy, ex, ey;
		cin>>sx>>sy>>ex>>ey;
		string d;
		cin>>d;
		mpp.SetStartEnd(sx, sy, GetDirection(d), ex, ey);
		//mpp.Print();
		//cout<<"==================="<<endl;
		//mpp.PrintVisited();
		mpp.FindPath();
	}
	return 0;
}


