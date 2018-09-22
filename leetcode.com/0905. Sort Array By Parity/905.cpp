/*
 * 905.cpp
 *
 *  Created on: Sep 22, 2018
 *      Author: frank
 */




class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        auto it = std::find_if(A.begin(), A.end(), [](const int i){ return i & 1; });
        while(it != A.end())
        {
            auto it2 = std::find_if(it+1, A.end(), [](const int i){ return !(i&1);});
            if(it2 == A.end())
                break;
            std::iter_swap(it, it2);
            it = std::find_if(it+1, A.end(), [](const int i){ return i & 1; });
        }
        return A;
    }
};
