/*
 * 394.cpp
 *
 *  Created on: Jun 14, 2017
 *      Author: franktang
 */
#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <map>
using namespace std;

class MultiArray
{
public:
    MultiArray() {}
    MultiArray(std::string line)
    {
        stringstream ss(line);
        ss>>name_>>base_addr_>>element_size_;
        int32_t bounds_count;
        ss>>bounds_count;
        std::vector<int32_t> dimensions;
        for(int32_t i = 0; i < bounds_count; ++i)
        {
            int32_t l, u;
            ss>>l>>u;
            bounds_.push_back(std::make_pair(l, u));
            dimensions.push_back(u - l + 1);
        }
        dimension_sizes_.resize(dimensions.size(), 1);
        for(int32_t index = dimension_sizes_.size() - 1; index >= 0; -- index)
        {
            if(index == dimension_sizes_.size() - 1)
            {
                dimension_sizes_[index] = 1;
                continue;
            }
            dimension_sizes_[index] *= (dimension_sizes_[index+1] * dimensions[index+1]);
        }
    }

    string Name() const { return name_; }
    int32_t BoundsSize() const { return bounds_.size(); }
public:
    void CalcIndex(std::vector<int32_t>& index)
    {
        int32_t result = 0;
        for(size_t i = 0; i < index.size(); ++i)
        {
            result += dimension_sizes_[i] * (index[i] - bounds_[i].first);
        }
        stringstream ss;
        ss<<name_<<"["<<index[0];
        for(size_t i = 1; i < index.size(); ++i)
        {
            ss<<", "<<index[i];
        }
        ss<<"] = "<<base_addr_ + element_size_ * result <<"\n";
        cout<<ss.str();
    }
private:
    string name_;
    int32_t base_addr_ = 0;
    int32_t element_size_ = 0;
    std::vector<std::pair<int32_t, uint32_t>> bounds_;
    std::vector<int32_t> dimension_sizes_;
};

int main()
{
    int32_t arrays, questions;
    std::map<string, MultiArray> array_map;
    string line;
    std::getline(cin, line);
    stringstream ss(line);
    ss>>arrays>>questions;
    for(int32_t i = 0; i < arrays; ++i)
    {
        std::getline(cin, line);
        MultiArray arr(line);
        array_map.insert(std::make_pair(arr.Name(), arr));
    }

    for(int32_t i = 0; i < questions; ++i)
    {
        std::getline(cin, line);
        stringstream ss(line);
        string name;
        ss>>name;
        int ds = array_map[name].BoundsSize();
        std::vector<int32_t> indexes;
        indexes.reserve(ds);
        for(int32_t ii = 0; ii < ds; ++ii)
        {
            int32_t index_i;
            ss>>index_i;
            indexes.push_back(index_i);
        }
        array_map[name].CalcIndex(indexes);
    }
    return 0;
}

