/*280.cpp
frank May 7, 2018
*/
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
 * 此题中，每个点默认是不能到达自己的，除非输入中明确指定自己到自己的边。
 */

void split(const std::string& str, const std::string& delimiters,
    std::vector<std::string>& tokens)
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

class Graph
{
public:
	Graph(int vc): vertex_count_(vc) {}
	void AddEdge(const string& line)
	{
		//cout<<"add edge: "<<line<<"\n";
		std::vector<string> v;
		split(line, " ", v);

		if(v.empty())
			return;

		int start = stoi(v[0]);

		for(size_t index = 1; index < v.size(); ++index)
		{
			int end = stoi(v[index]);
			if(end == 0)
				break;

			//cout<<"add point: "<<start<<", "<<end<<"\n";
			edges_[start].insert(end);
		}
	}

	void Process(string line) // 读取一行
	{
		//cout<<"process: "<<line<<"\n";
		vector<string> v;
		split(line, " ", v);

		if(v.empty())
			return;

		int qc = stoi(v[0]);
		for(size_t index = 1; index < v.size(); ++index)
		{
			int check = stoi(v[index]);
			FindUnreachable(check);
		}
	}
private:
	void FindUnreachable(int v) // 找出顶点v不能到达的点
	{
		//cout<<"FindUnreachable:"<<v<<"\n";
		visited_.clear();
		visited_.resize(vertex_count_ + 1, 0);
		visited_[0] = 1; // 第0个不用

		auto it = edges_.find(v);
		if(it != edges_.end())
		{
			const auto& s = it->second;
			for(int end: s)
			{
				if(0 == visited_[end])
					DFS(v);
			}
		}

		// 每个定点v默认不能到达自己，除非输入中含有(v, v)
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
	string line;
	while(std::getline(cin, line))
	{
		if(line.empty())
			continue;

		if(line[0] == '0')
			break;

		int vc = std::stoi(line);
		Graph g(vc);
		//cout<<"vc="<<vc<<"\n";

		string l;
		while(std::getline(cin, l))
		{
			if(l.empty())
				continue;

			if(l[0] == '0')
				break;

			g.AddEdge(l);
		}

		string questions;
		std::getline(cin, questions);
		g.Process(questions);
	}

	return 0;
}


