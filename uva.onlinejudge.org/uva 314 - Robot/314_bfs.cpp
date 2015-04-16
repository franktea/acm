/*
 * 314_bfs.cpp
 *
 *	uva 314 - Robot (bfs)
 *
 *  Created on: Mar 7, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <list> // 作为bfs需要的队列使用
#include <stdint.h>
#include <assert.h>

using namespace std;

/**
 * bfs方法时，把每个点拆成四个点，bfs的层级以时间为单位，1秒种扫一层，
 * 每个点可以进行5种动作：左转(坐标不变)、右转(坐标不变)、向前1步(方向不变)、向前2步(方向不变)、向前3步(方向不变)；
 * 向后转需要2秒钟，已经拆成2步：先向左再向左、或者先向右再向右，只要按照上面的5个动作的步骤，2秒后一定会向后转。
 */

enum Direction { north = 0, east, south, west};
// 四个方向的5个动作对应的x(行）、y（列）和方向的变化
const vector<vector<int32_t> > DX = { {0, 0, -1, -2, -3}, // 面朝north时对应的向左转、向右转、向前一步、向前2步、向前3步的x变化
		{0, 0, 0, 0, 0}, // 面朝east时
		{0, 0, 1, 2, 3}, // 面朝south时
		{0, 0, 0, 0, 0}}; // 面朝west时
const vector<vector<int32_t> > DY = { {0, 0, 0, 0, 0}, // 四个方向5个动作对应的y的变化
		{0, 0, 1, 2, 3},
		{0, 0, 0, 0, 0},
		{0, 0, -1, -2, -3}};
//四个方向5个动作对应的方向的变化
const vector<vector<Direction> > DD = { {west, east, north, north, north},
		{north, south, east, east, east},
		{east, west, south, south, south},
		{south, north, west, west, west}};

class RobotModel
{
	struct RuntimeData // 运行时存储在队列中的数据结构。
	{
		int32_t x;
		int32_t y;
		Direction d;
		int32_t level; // 层级，也就是时间，为多少秒钟，从0开始。
	};
public:
	RobotModel(int32_t m, int32_t n): M_(m), N_(n)
	{
		value_.resize(M_*N_);
		visited_.resize(M_*N_*4);
	}

	void BFS(const int32_t start_x, const int32_t start_y, const Direction start_d,
			const int32_t end_x, const int32_t end_y)
	{
		if(!CanGo(start_x, start_y) || !CanGo(end_x, end_y))
		{
			cout<<"-1\n";
			return;
		}

		queue_.push_back(RuntimeData{start_x, start_y, start_d, 0});
		Visited(start_x, start_y, start_d) = 1;
		bool found = false;
		while(! found && ! queue_.empty())
		{
			const RuntimeData rd = queue_.front();
			queue_.pop_front();
			if(rd.x == end_x && rd.y == end_y)
			{
				cout<<rd.level<<"\n";
				found = true;
				break;
			}

			for(int32_t i = 0; i < 5; ++i)
			{
				const int32_t x = rd.x + DX[rd.d][i];
				const int32_t y = rd.y + DY[rd.d][i];
				const Direction d= DD[rd.d][i];

				if(! CanGo(x, y) || Visited(x, y, d)) continue;

				RuntimeData next_rd = {x, y, d, rd.level+1};
				//cout<<x<<" "<<y<<" "<<d<<" level="<<next_rd.level<<endl;
				if((x == rd.x && y == rd.y) || CanGoFromTo(rd, next_rd))
				{
					//cout<<x<<" "<<y<<" "<<d<<" level="<<next_rd.level<<"<============="<<endl;
					Visited(x, y, d) = 1;
					queue_.push_back(next_rd);
				}
			}
		}
		if(!found) cout<<"-1\n";
	}

	int32_t& Value(int32_t x, int32_t y)
	{
		return value_[N_*x + y];
	}
private:
	int32_t& Visited(int32_t x, int32_t y, Direction d)
	{
		//cout<<x<<","<<y<<","<<d<<", = "<<x*(N_*4) + y*4 + d<<", value="<<visited_[x*(N_*4) + y*4 + d]<<endl;
		return visited_[x*(N_*4) + y*4 + d];
	}

	bool CanGoFromTo(const RuntimeData& pos1, const RuntimeData& pos2)
	{
		assert(pos1.d == pos2.d);
		if(pos1.x == pos2.x)
		{
			const int32_t min_y = std::min(pos1.y, pos2.y);
			const int32_t max_y = std::max(pos1.y, pos2.y);
			for(int32_t yy = min_y+1; yy < max_y; ++yy)
				if(!CanGo(pos1.x, yy)) return false;
		}
		else if(pos1.y == pos2.y)
		{
			const int32_t min_x = std::min(pos1.x, pos2.x);
			const int32_t max_x = std::max(pos1.x, pos2.x);
			for(int32_t xx = min_x+1; xx < max_x; ++xx)
				if(!CanGo(xx, pos1.y)) return false;
		}

		return true;
	}

	bool CanGo(int32_t x, int32_t y)
	{
		return (x-1) >= 0 && //(x-1) < M_ &&
				(y-1) >= 0 && //(y-1) < N_ &&
				/*x >= 0 &&*/ x < M_ &&
				/*y >= 0 &&*/ y < N_ &&
				!(Value(x-1, y-1)||Value(x-1, y)||Value(x, y-1)||Value(x, y));
	}
private:
	const int32_t M_;
	const int32_t N_;
	vector<int32_t> value_; // 从stdin读进来的初始化数据，是2维数组，大小为M*N，每个元素值为0或者1
	vector<int32_t> visited_; // bfs记录每个点状态的数组，为3维数组，大小为M*N*4，用Visited(x,y,d)函数来访问对应元素
	list<RuntimeData> queue_; // 用作bfs的队列
};

Direction GetDirection(std::string d)
{
	if(d == "east") return east;
	if(d == "west") return west;
	if(d == "north") return north;

	return south;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int32_t M, N;
	while(cin>>M>>N)
	{
		if(M == 0 && N == 0) break;
		RobotModel rm(M, N);
		for(int32_t x = 0; x < M; ++x)
		{
			for(int32_t y = 0; y < N; ++y)
			{
				int32_t data;
				cin>>data;
				rm.Value(x, y) = data;
			}
		}
		int32_t sx, sy, ex, ey;
		cin>>sx>>sy>>ex>>ey;
		string d;
		cin>>d;
		rm.BFS(sx, sy, GetDirection(d), ex, ey);
	}
	return 0;
}
