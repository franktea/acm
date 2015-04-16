/*
 * 108.cpp
 *
 *  title : Maximum Sum
 *
 *  Created on: Feb 5, 2015
 *      Author: franktang
 */

#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <string.h> // for bzero
#include <limits>
#include <iomanip>

using namespace std;

const int32_t MAX_POSSIBLE_ARRAY_SIZE = 101;

template<int32_t MAXROWS, int32_t MAXCOLUMNS>
int32_t MaxMatrix(const int32_t m, const int32_t n, int32_t matrix[MAXROWS][MAXCOLUMNS])
{
    // 用一个三维数组，维度分别为i、j、k，用来保存在第i~j行之间、第k列的和
    int32_t sum_column[MAXROWS][MAXROWS][MAXCOLUMNS];
    bzero(sum_column, sizeof(sum_column));
//    for(int32_t i = 0; i < MAXROWS; ++i)
//        for(int32_t j = 0; j < MAXROWS; ++j)
//            for(int32_t k = 0; k < MAXCOLUMNS; ++k)
//                cout<<sum_column[i][j][k];
//    cout<<"============="<<endl;

    int32_t result = std::numeric_limits<int32_t>::min();
    // 这几个变量用来记录最大的和出现时的矩形所在的位置，就是第[maxi, maxj]行、第[maxk, maxl]列
    // 当maxi == maxj时，表示就是第maxi行
    int32_t maxi, maxj, maxk, maxl;
    maxi = maxj = maxk = maxl = -1;
    for(int32_t i = 1; i <= m; ++i)
    {
        for(int32_t j = i; j <= m; ++j)
        {
            for(int32_t k = 1; k <= n; ++k)
            {
                sum_column[i][j][k] = sum_column[i][j-1][k] + matrix[j][k];
                //cout<<i<<", "<<j<<", "<<k<<": "<<sum_column[i][j][k]<<". ";
            }

            // 从i~j行所有列的和都已经算出来了，在数组sum_column[i][j][k]中，1 <= k <= n
            // 现在从这里面查找连续和最大的，因为i、j此时不变，所以相当于从一维数组中选取连续和最大的
            int32_t max_k_sum = sum_column[i][j][1];
            if(result < max_k_sum)
            {
                result = max_k_sum;
                maxi = i; maxj = j; maxk = 1; maxl = 1;
            }
            int32_t current_max_k = 1;
            for(int32_t k = 2; k <= n; ++k) // 计算以第k列结尾的连续最大的和及其位置
            {
                if(max_k_sum > 0)
                {
                    max_k_sum += sum_column[i][j][k];
                }
                else
                {
                    max_k_sum = sum_column[i][j][k];
                    current_max_k = k;
                }

                if(max_k_sum > result)
                {
                    result = max_k_sum;
                    maxi = i;
                    maxj = j;
                    maxk = current_max_k;
                    maxl = k;
                }
            }
            //cout<<"result = "<<result<<"\n";
        }
        //cout<<"\n";
    }

    //cout<<"final result:"<<result<<", (i, j, k, l)=("<<maxi<<", "<<maxj<<", "<<maxk<<", "<<maxl<<")"<<endl;
    return result;
}

int main()
{
    int32_t array[MAX_POSSIBLE_ARRAY_SIZE][MAX_POSSIBLE_ARRAY_SIZE];
    int32_t N;
    cin>>N;
    //cout<<"N is "<<N<<endl;
    for(int32_t i = 1; i <= N; ++i)
        for(int32_t j = 1; j <= N; ++j)
            cin>>array[i][j];

//    for(int32_t i = 1; i <=N; ++i)
//    {
//        for(int32_t j = 1; j < N; ++j)
//        {
//            cout<<std::setw(4)<<array[i][j];
//            cout<<",";
//        }
//        cout<<std::setw(4)<<array[i][N];
//        cout<<"\n";
//    }
    cout<<MaxMatrix<MAX_POSSIBLE_ARRAY_SIZE, MAX_POSSIBLE_ARRAY_SIZE>(N, N, array)<<"\n";
    return 0;
}

