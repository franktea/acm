/*
 * 437.cpp
 *  uva 437 - The Tower of Babylon
 *  Created on: Apr 19, 2017
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <stdint.h>
using namespace std;

struct Box
{
    int32_t a, b, c;
};

bool operator<(const Box& lhs, const Box& rhs)
{
    return lhs.a < rhs.a && lhs.b < rhs.b;
}

string ToString(const Box& b)
{
    stringstream ss;
    ss<<b.a<<"|"<<b.b<<"|"<<b.c;
    return ss.str();
}

struct DeleteDuplicate
{
    bool operator()(const Box& lhs, const Box& rhs) const
    {
        return ToString(lhs) < ToString(rhs);
    }
};

class LisBox
{
public:
    LisBox(int32_t no, int32_t lines):no(no){boxes.reserve(3*lines);}

    void Add(int32_t a, int32_t b, int32_t c)
    {
        vector<int32_t> v = {a, b, c};
        sort(v.begin(), v.end());
        all.insert(Box{v[0], v[1], v[2]});
        all.insert(Box{v[1], v[2], v[0]});
        all.insert(Box{v[0], v[2], v[1]});
    }

    void Solve()
    {
        for(auto& b: all)
            boxes.push_back(b);
        sort(boxes.begin(), boxes.end(), [](const Box& lhs, const Box& rhs) -> bool
                {
                    if(lhs.b != rhs.b) return lhs.b > rhs.b;
                    return lhs.a > rhs.a;
                });

        vector<int32_t> lises(boxes.size(), 0);
        for(size_t i = 0; i < boxes.size(); ++i)
        {
            lises[i] = boxes[i].c;
        }

        int32_t ans = 0;
        for(size_t i = 0; i < boxes.size(); ++i)
        {
            int32_t cur = 0;
            for(size_t j = 0; j < i; ++j)
            {
                if(boxes[i] < boxes[j])
                {
                    cur = max(cur, lises[j] + boxes[i].c);
                    ans = max(ans, cur);
                }
            }
            lises[i] = max(boxes[i].c, cur);
        }

        cout<<"Case "<<no<<": maximum height = "<<ans<<"\n";
    }
private:
    int32_t no; //case index
    set<Box, DeleteDuplicate> all;
    vector<Box> boxes;
};

int main()
{
    int32_t no = 0;
    int32_t cnt;
    cin>>cnt;
    while(cnt)
    {
        LisBox lb(++no, cnt);
        int32_t a, b, c;
        while(cnt--)
        {
            cin>>a>>b>>c;
            lb.Add(a, b, c);
        }
        lb.Solve();
        cin>>cnt;
    }
    return 0;
}



