/*
 * 469.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * dfs, 与uva 352、572，以及poj2386数水洼的类似。
 */

using namespace std;

template<typename T, std::size_t N>
std::size_t array_size(T(&)[N])
{
    return N;
}

const int32_t DX[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int32_t DY[] = {-1, 0, 1, 1, 1, 0, -1, -1};

class Graph
{
    struct PositionArea
    {
        int32_t parent_x;
        int32_t parent_y;
        int32_t area;
    };
public:
    Graph(vector<string>& graph, int32_t M, const vector<std::pair<int32_t, int32_t> >& ps):
        N_(graph.size()), M_(M), graph_(graph), ps_(ps)
    {
        parent_.resize(N_*M_, PositionArea{-1, -1, -1});
    }

    void Solve()
    {
        for(int32_t x = 0; x < N_; ++x)
            for(int32_t y = 0; y < M_; ++y)
                if(graph_[x][y] == 'W')
                    Parent(x, y).area = DFS(x, y);

        for(const std::pair<int32_t, int32_t>& p: ps_)
        {
            cout<<GetArea(p.first-1, p.second-1)<<"\n";
        }
    }
private:
    int32_t DFS(const int32_t x, const int32_t y)
    {
        graph_[x][y] = 'L';

        int32_t result = 1;

        for(size_t i = 0; i < array_size(DX); ++i)
        {
            int32_t x2 = x + DX[i];
            int32_t y2 = y + DY[i];
            if(! Valid(x2, y2) || graph_[x2][y2] != 'W') continue;

            PositionArea& pa = Parent(x2, y2);
            pa.parent_x = x;
            pa.parent_y = y;
            result += DFS(x2, y2);
        }

        return result;
    }

    bool Valid(int32_t x, int32_t y)
    {
        return x >= 0 && x < N_ && y >= 0 && y < M_;
    }

    PositionArea& Parent(int32_t x, int32_t y)
    {
        return parent_[x*M_ + y];
    }

    int32_t GetArea(int32_t x, int32_t y)
    {
        PositionArea& pa = Parent(x, y);
        while(pa.parent_x != -1)
            pa = Parent(pa.parent_x, pa.parent_y);
        return pa.area;
    }
private:
    const int32_t N_; // 行数
    const int32_t M_; // 列数
    vector<string>& graph_;
    const vector<std::pair<int32_t, int32_t> >& ps_;
    vector<PositionArea> parent_; // 用来实现并查集, 每个节点所有的值为-1表示无父节点
};

//void Tokenize(const string& str,
//                      vector<string>& tokens,
//                      const string& delimiters = " ")
//{
//    string::size_type last_pos = str.find_first_not_of(delimiters, 0);
//    string::size_type pos     = str.find_first_of(delimiters, last_pos);
//
//    while (string::npos != pos || string::npos != last_pos)
//    {
//        tokens.push_back(str.substr(last_pos, pos - last_pos));
//        last_pos = str.find_first_not_of(delimiters, pos);
//        pos = str.find_first_of(delimiters, last_pos);
//    }
//}
//
//std::pair<int32_t, int32_t> ToInt2(const string& line)
//{
//    cout<<"toint2: "<<line<<endl;
//    vector<string> v(2, "");
//    Tokenize(line, v, " \t");
//    assert(v.size() == 2);
//    return std::pair<int32_t, int32_t> {atoi(v[0].c_str()), atoi(v[1].c_str())};
//}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    vector<string> graph;
    graph.reserve(100);
    string line;
    int32_t case_count;
    cin>>case_count>>line;
    bool finished = false;
    for(int32_t i = 0; i < case_count && !finished; ++i)
    {
    	if(i > 0) cout<<"\n";

        graph.clear();
        vector<std::pair<int32_t, int32_t> > ps; // 最后的k行需要求大小的数据坐标
        ps.reserve(10);
        int32_t n, m; // 行数和列数
        while(line[0] == 'L' || line[0] == 'W')
        {
            m = line.size();
            graph.push_back(line);
            cin>>line;
        }

        while(line[0] != 'L' && line[0] != 'W') // 需要求面积的坐标
        {
            std::pair<int32_t, int32_t> p;
            p.first = atoi(line.c_str());
            cin>>line;
            p.second = atoi(line.c_str());
            ps.push_back(p);
            //cout<<p.first<<" "<<p.second<<endl;
            if(!(cin>>line))
            {
            	break;
            	finished = true;
            }
        }

        Graph g(graph, m, ps);
        g.Solve();
    }
    return 0;
}
