/*280.cpp
frank May 7, 2018
*/
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 此题中，每个点默认是不能到达自己的，除非输入中明确指定自己到自己的边。
 */

class Graph
{
public:
	Graph(int vc): vertex_count_(vc) {}
	void AddEdge(int start)
	{
		cout<<"start::::"<<start<<"\n";
		int v;
		cin>>v;
		while(v) // v != 0
		{
			cout<<"get v:"<<v<<"\n";

			edges_[start].insert(v);
			cin>>v;
		}
	}

	void Process() // 读取一行
	{
		int vc;
		cin>>vc;
		cout<<"====>"<<vc<<"\n";
		while(vc--)
		{
			cout<<"11111"<<"\n";
			int v;
			cout<<"22222"<<"\n";
			cin>>v;
			cout<<"33333"<<v<<"\n";
			FindUnreachable(v);
		}
	}
private:
	void FindUnreachable(int v) // 找出顶点v不能到达的点
	{
		cout<<"FindUnreachable:"<<v<<"\n";
		visited_.clear();
		visited_.resize(vertex_count_ + 1, 0);
		visited_[0] = 1; // 第0个不用
		DFS(v);

		// 每个定点v默认不能到达自己，除非输入中含有(v, v)
		auto it = edges_.find(v);
		visited_[v] = it->second.find(v) == it->second.end() ? 0 : 1;

		auto c = std::count(visited_.begin(), visited_.end(), 0);
		cout<<c;
		for(size_t i = 1; i < visited_.size(); ++i)
		{
			if(visited_[i] == 0)
			{
				cout<<" "<<i;
			}
		}
		cout<<"\n";
	}

	void DFS(int v)
	{
		auto it = edges_.find(v);
		if(it != edges_.end())
		{
			visited_[it->first] = 1;
			const auto& s = it->second;
			for(auto v2: s)
			{
				if(0 == visited_[v2])
					DFS(v2);
			}
		}
	}
private:
	std::vector<int> visited_; // 全局变量
	const int vertex_count_; // 顶点个数
	std::map<int, std::set<int>> edges_; // 所有的边，[k, v]表示以k为起点v为终点的边
};

int main()
{
	int vc;
	cin>>vc;
	while(vc)
	{
		Graph g(vc);
		int v;
		cin>>v;
		while(v)
		{
			g.AddEdge(v);
			cin>>v;
		}
		g.Process();

		cin>>vc;
	}

	return 0;
}


