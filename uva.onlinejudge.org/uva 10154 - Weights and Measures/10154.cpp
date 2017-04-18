/*
 * 10154.cpp
 *  uva 10154 - Weights and Measures
 *  Created on: Apr 18, 2017
 *      Author: franktang
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <map>
#include <stdint.h>

using namespace std;

struct Turtle
{
    int32_t weight;
    int32_t strength;
};

struct Sortby
{
    bool operator()(const Turtle& lhs, const Turtle& rhs) const
    {
        return lhs.strength > rhs.strength;
    }
};

vector<Turtle> turtles;
//map<std::pair<int32_t, int32_t>, int32_t> val_map; // save intermediate result here
vector<map<int32_t, int32_t>> results;

int32_t Val(int32_t index, int32_t capacity)
{
    if(index == turtles.size()) return 0;
    if(capacity == 0) return 0;

//    auto it = val_map.find(std::make_pair(index, capacity));
//    if(it != val_map.end())
//        return it->second;
    auto it = results[index].find(capacity);
    if(it != results[index].end())
        return it->second;

    int32_t v;
    auto& t = turtles[index];
    if(capacity == -1)
    {
        v = max(Val(index+1, capacity), 1+Val(index+1, t.strength - t.weight));
    }
    else
    {
        if(t.weight > capacity)
            v = Val(index+1, capacity);
        else
            v = max(Val(index+1, capacity), 1+Val(index+1, min(capacity - t.weight, t.strength - t.weight)));
    }

    //val_map.insert({std::make_pair(index, capacity), v});
    results[index].emplace(std::pair<int32_t, int32_t>{capacity, v});
    return v;
}

int main()
{
    turtles.reserve(5607);
    int32_t w, s;
    while(cin>>w>>s)
    {
        turtles.emplace_back(Turtle{w, s});
    }
    results.resize(turtles.size());
    sort(turtles.begin(), turtles.end(), Sortby());
    cout<<Val(0, -1)<<"\n";
//    int32_t ct = 0;
//    for(auto& m: results)
//    {
//        ct += m.size();
//    }
//    cout<<"totalsize:"<<ct<<endl;
    return 0;
}


