/*
 * 10004.cpp
 *
 *  uva 10004 - Bicoloring
 *
 *  Created on: Jan 10, 2016
 *      Author: frank
 */

#include <iostream>
#include <stdint.h>
#include <map>
#include <vector>

using namespace std;

class BiCase
{
public:
	BiCase(int32_t vertice_count)
	{
		graph_.resize(vertice_count);
		for(int32_t i = 0; i < vertice_count; ++i)
		{
			color_map_.insert(std::make_pair(i, 0));
		}
	}

	void AddEdge(int32_t v1, int32_t v2)
	{
		graph_[v1].push_back(v2);
		graph_[v2].push_back(v1);
	}

	bool SolveVertice(int32_t v)
	{
		const vector<int32_t>& neighbours = graph_[v];
		const int32_t neighbour_color = color_map_[v] == 1 ? 2 : 1;
		for(size_t i = 0; i < neighbours.size(); ++i)
		{
			int32_t& color = color_map_[neighbours[i]];
			if(color == 0)
			{
				color = neighbour_color;
				return SolveVertice(neighbours[i]);
			}
			else if(color != neighbour_color)
			{
				return false;
			}
		}

		return true;
	}

	bool Solve()
	{
		color_map_[0] = 1;
		for(size_t i = 0; i < graph_.size(); ++i)
		{
			const int32_t neighbour_color = color_map_[i] == 1 ? 2 : 1;
			const vector<int32_t>& neighbours = graph_[i];
			for(size_t j = 0; j < neighbours.size(); ++j)
			{
				if(color_map_[neighbours[j]] != 0 && color_map_[neighbours[j]] != neighbour_color)
				{
					return false;
				}
				else
				{
					color_map_[neighbours[j]] = neighbour_color;
					if(!SolveVertice(neighbours[j]))
						return false;
				}
			}
		}

		return true;
	}
private:
	std::map<int32_t, int32_t> color_map_; // 每个点被染成了什么颜色，为0、1、2。分别表示未染色、颜色1、颜色2
	std::vector<vector<int32_t> > graph_; // 邻接表
};

int main()
{
	int32_t vertice_count;
	while(cin>>vertice_count && vertice_count)
	{
		BiCase bc(vertice_count);
		int32_t edge_count;
		cin>>edge_count;
		int32_t v1, v2;
		while(edge_count--)
		{
			cin>>v1>>v2;
			bc.AddEdge(v1, v2);
		}
		if(bc.Solve())
			cout<<"BICOLORABLE.\n";
		else
			cout<<"NOT BICOLORABLE.\n";
	}

	return 0;
}


