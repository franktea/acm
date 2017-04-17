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
        slices.reserve(slice_count+1); // 原始数据，每一段的长度
        indexes.resize(slice_count+1, 0); // 递归的时候使用，每一段被选中的在slices数组中的下标，也是最终排列的结果，只是本题不要求输出此结果
        index_used.resize(slice_count+1, 0); // 递归的时候使用，记录每一段是否使用过
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

    size_t from_index = sum == 0 ? 1 : indexes[index-1] + 1; //如果不是小棍的第一截，则后面每一段的下标一定比前面的大，加上这一句以后优化了非常多
    for(size_t i = from_index; i < slices.size();++i)
    {
        if(0 != index_used[i] ||
                sum + slices[i] > length) continue;
        indexes[index] = i;
        index_used[i] = 1;
        if(! Recursive(index+1, sum + slices[i] == length ? 0 : sum + slices[i], length))
        {
            index_used[i] = 0;
            if(sum == 0) return false; // 如果第一段都失败了，则整根肯定都失败了
            //if(slices[i] == slices[slices.size()-1]) return false; // 如果最短的都用掉了，则不用再试了
            while(i+1 < slices.size() && slices[i+1] == slices[i]) ++i; // 如果当前长度失败了，则后面相同的长度全部跳过
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

