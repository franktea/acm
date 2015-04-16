/*
 * 291.cpp
 *
 *  uva 291 - The House Of Santa Claus
 *
 *  Created on: Mar 4, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <bitset>
#include <stdint.h>

using namespace std;

bool Get(bitset<32>& visited, int32_t x, int32_t y)
{
    if(x > y) std::swap(x, y);
    return visited.test(x*5+y);
}

void Set(bitset<32>& visited, int32_t x, int32_t y, bool value)
{
    if(x > y) std::swap(x, y);
    visited.set(x*5+y, value);
}

void DFS(vector<vector<int32_t> >& graph, vector<int32_t>& path,
        bitset<32>& visited, const int32_t vertex, const int32_t level)
{
    path[level] = vertex;
    if(8 == level) // 9个点连接8条边，点可以重复，但是边不能重复
    {
        std::ostream_iterator<int32_t> out_it(cout, "");
        std::copy(path.begin(), path.end(), out_it);
        cout<<"\n";
        return;
    }

    vector<int32_t> near_vertexes = graph[vertex];
    for(int32_t v: near_vertexes)
    {
        if(Get(visited, vertex, v)) continue;
        Set(visited, vertex, v, true);
        DFS(graph, path, visited, v, level+1);
        Set(visited, vertex, v, false);
    }
}

int main()
{
    vector<vector<int32_t> > graph = { {}, {2, 3, 5}, {1, 3, 5}, {1, 2, 4, 5},
            {3, 5}, {1, 2, 3, 4} }; // 点编号从1开始，0不使用，必须为空，否则越界
    vector<int32_t> path(9, 0); // 结果有9个点，存在这里面，在最后需要输出
    bitset<32> visited(0); // 每个点在当前dfs路径上是否被放问过
    DFS(graph, path, visited, 1, 0);
    return 0;
}
