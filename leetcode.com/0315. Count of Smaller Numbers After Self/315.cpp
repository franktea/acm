/*
 * 315.cpp
 *
 *  Created on: Sep 30, 2019
 *      Author: frank
 */
#include <vector>
#include <iostream>
#include <set>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        result.resize(nums.size());
        if(nums.empty())
        {
            return result;
        }

        multiset<int> m;
        for(int index = nums.size() - 1; index >= 0; --index)
        {
            auto it = m.lower_bound(nums[index]);
/*            cout<<"index="<<index<<", "<<"distance="<<std::distance(m.begin(), it)<<", m=[";
            for(int i: m)
            {
                cout<<i<<", ";
            }
            cout<<"]\n";
*/
            result[index] = std::distance(m.begin(), it);
            m.insert(nums[index]);
        }

        return result;
    }
};
static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

int main()
{
    std::vector<int> v = {3, 1, 1, 0, 1, 9, 4};
    Solution s;
    std::vector<int> v2 = s.countSmaller(v);
    for(int i: v2)
    {
        cout<<i<<", ";
    }
    cout<<"\n";
    return 0;
}


