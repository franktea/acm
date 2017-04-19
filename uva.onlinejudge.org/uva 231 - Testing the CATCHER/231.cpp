/*
 * 231.cpp
 *  uva 231 - Testing the CATCHER
 *  Created on: Apr 19, 2017
 *      Author: franktang
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
using namespace std;

class Lis
{
public:
    Lis(int32_t no):no(no){}
    void Input()
    {
        int32_t value;
        cin>>value;
        while(-1 != value)
        {
            data.push_back(value);
            cin>>value;
        }
    }

    bool Solve()
    {
        if(data.empty()) return false;
        vector<int32_t> lises(data.size(), 1);
        int32_t ans = 1;
        for(size_t i = 0; i < data.size(); ++i)
        {
            int32_t cur = 1;
            for(size_t j = 0; j < i; ++j)
            {
                if(data[j] >= data[i])
                {
                    cur = max(cur, lises[j] + 1);
                    ans = max(cur, ans);
                }
            }
            lises[i] = cur;
        }
        if(no > 1) cout<<"\n";
        cout<<"Test #"<<no<<":\n  "
                "maximum possible interceptions: "<<ans<<"\n";
        return true;
    }
private:
    vector<int32_t> data;
    int32_t no;
};

int main()
{
    int32_t no = 0;
    while(1)
    {
        Lis lis(++no);
        lis.Input();
        if(! lis.Solve())
            break;
    }
    return 0;
}



