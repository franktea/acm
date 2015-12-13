/*
 * 101.cpp
 *
 *  Created on: Dec 13, 2015
 *      Author: frank
 */

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdint.h>

using namespace std;

class block
{
    friend class slots;
private:
    int32_t number_;
public:
    block(int32_t n): number_(n) {}
    int32_t Number() const { return number_; }
    bool operator==(int32_t number) const
    {
        return number_ == number;
    }
};

class slots
{
public:
    slots(const int32_t count): count_(count)
    {
        slots_.resize(count_);
        for(int32_t i = 0; i < count_; ++i)
        {
            slots_[i].push_back(block(i));
        }
    }

    void OutPut()
    {
        for(int32_t i = 0; i < count_; ++i)
        {
            cout<<i<<":";
            for(list<block>::iterator it = slots_[i].begin();
                it != slots_[i].end(); ++it)
            {
                cout<<" "<<it->Number();
            }
            cout<<endl;
        }
    }

    void Move(int32_t number_a, int32_t number_b, bool onto = false)
    {
        int32_t index_a, index_b;
        auto fr = Find(number_a, index_a);
        if(!fr.first)
        {
            cout<<"not found"<<number_a<<endl;
        }
        list<block>::iterator it_a = fr.second;
        //cout<<"found index_a="<<index_a<<", value:"<<it_a->Number()<<endl;

        fr = Find(number_b, index_b);
        if(! fr.first)
        {
            cout<<"not found"<<number_a<<endl;
        }
        list<block>::iterator it_b = fr.second;
        //cout<<"found index_b="<<index_b<<", value:"<<it_b->Number()<<endl;

        if(index_a == index_b)
        {
            return;
        }

        Move(index_a, it_a);
        if(onto)
        {
            Move(index_b, it_b);
        }

        block bl = slots_[index_a].back();
        slots_[index_a].pop_back();
        slots_[index_b].push_back(bl);
    }

    void Pile(int32_t number_a, int32_t number_b, bool onto = false)
    {
        int32_t index_a, index_b;
        auto fr = Find(number_a, index_a);
        if(!fr.first)
        {
            cout<<"not found"<<number_a<<endl;
        }
        list<block>::iterator it_a = fr.second;
        //cout<<"found index_a="<<index_a<<", value:"<<it_a->Number()<<endl;

        fr = Find(number_b, index_b);
        if(! fr.first)
        {
            cout<<"not found"<<number_a<<endl;
        }
        list<block>::iterator it_b = fr.second;
        //cout<<"found index_b="<<index_b<<", value:"<<it_b->Number()<<endl;

        if(index_a == index_b) // 这个判断必须加
        {
            return;
        }

        if(onto)
        {
            Move(index_b, it_b);
        }

        slots_[index_b].splice(slots_[index_b].end(), slots_[index_a], it_a, slots_[index_a].end());
    }
private:
    void Move(int32_t index, list<block>::iterator it)
    {
        while(slots_[index].back().Number() != it->Number())
        {
            block bl = slots_[index].back();
            slots_[index].pop_back();
            slots_[bl.Number()].push_back(bl);
        }
    }

    std::pair<bool, list<block>::iterator> Find(int32_t number, int32_t& index)
    {
        for(int32_t i = 0; i < count_; ++i)
        {
            list<block>::iterator r = std::find(slots_[i].begin(), slots_[i].end(), number);
            if(r != slots_[i].end())
            {
                index = i;
                return std::make_pair(true, r);
            }
        }

        return std::make_pair(false, list<block>::iterator());
    }
private:
    const int32_t count_;
    vector<list<block> > slots_;
};

int main()
{
    std::ios::sync_with_stdio(false);

    int32_t block_count = 0;
    cin>>block_count;
    slots slt(block_count);

    int32_t lines = 0;

    while(1)
    {
        string verb; // 动词，move or pile
        int32_t block_a;
        string preposition; // 介词 over or onto
        int32_t block_b;
        cin>>verb;
        if(verb == "quit")
        {
            break;
        }
        cin>>block_a>>preposition>>block_b;
        //cout<<verb<<" "<<block_a<<" "<<preposition<<" "<<block_b<<endl;

        if(block_a == block_b) // 这个判断必须加
        {
            continue;
        }

        if(verb == "move")
        {
            slt.Move(block_a, block_b, preposition == "onto");
        }
        else
        {
            slt.Pile(block_a, block_b, preposition == "onto");
        }

        //cout<<"line:"<<++lines<<endl;
    }
    slt.OutPut();
    return 0;
}



