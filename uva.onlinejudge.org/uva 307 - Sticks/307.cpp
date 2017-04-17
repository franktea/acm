/*
 * 307.cpp
 *  uva 307 - Sticks
 *  Created on: Apr 12, 2017
 *      Author: franktang
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // std::greater
#include <numeric> // std::accumulate
#include <stdint.h>

using namespace std;

class Stick
{
public:
    Stick(int32_t slice_count)
    {
        slices.reserve(slice_count+1);
        indexes.resize(slice_count+1, 0);
        index_used.resize(slice_count+1, 0);
        slices.push_back(0);
    }

    void AddSlice(int32_t v)
    {
        slices.push_back(v);
    }

    void Solve();
private:
    bool Recursive(const int32_t index, const int32_t sum, const int32_t length);
private:
    vector<int32_t> slices;
    vector<int32_t> indexes;
    vector<size_t> index_used;
};

void Stick::Solve()
{
    sort(slices.begin() + 1, slices.end(), greater<int>());
    const int32_t big_slice = slices[1];
    const int32_t total_length = std::accumulate(slices.begin(), slices.end(), 0);
    for(int32_t length = big_slice; length <= total_length/2; ++length)
    {
        if(total_length % length) continue;
        if(Recursive(1, 0, length)) return;
    }
    cout<<total_length<<"\n";
}

bool Stick::Recursive(const int32_t index, const int32_t sum, const int32_t length)
{
    //cout<<"index: "<<index<<"\n";
    if(index > slices.size() - 1)
    {
        cout<<length<<"\n";
        return true;
    }

    size_t from_index = sum == 0 ? 1 : indexes[index-1] + 1;
    for(size_t i = from_index; i < slices.size();++i)
    {
        if(0 != index_used[i] ||
                sum + slices[i] > length) continue;
        indexes[index] = i;
        index_used[i] = 1;
        if(! Recursive(index+1, sum + slices[i] == length ? 0 : sum + slices[i], length))
        {
            index_used[i] = 0;
            if(sum == 0) return false;
            while(i+1 < slices.size() && slices[i+1] == slices[i]) ++i;
        }
        else
            return true;
    }

    return false;
}



int main()
{
    int32_t count;
    cin>>count;
    while(0 != count)
    {
        Stick st(count);
        for(int32_t i = 0; i < count; ++i)
        {
            int32_t len;
            cin>>len;
            st.AddSlice(len);
        }
        st.Solve();

        cin>>count;
    }
    return 0;
}

