/*
 * 132_2.cpp
 *
 *  Created on: Sep 16, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// 用了算是dp的方法，总算过了，虽然只打败18%，但是还是要庆祝一下。思路如下：
// 先遍历一边字符串，把每两个位置之间是否回文全部算出来。
// 用arr[i][j], 0<=i<=j<s.length来记录，用O(N^N)来遍历，其中判断是否回文又是O(N)的复杂度，
// 计算arr为O(N^3)的复杂度。
// arr计算出来以后，对于字符串的串s[0..N], 0<=N<s.length，用f(n)来表示其最小切分次数，则：
// f(n) = 0 , 字串s[0..N]是回文，即arr[0][N] == 1
// f(n) = min(f(i) + arr[i+1][N]), 0 <= i < N 且 arr[i+1][N] == 1
// 计算这个过程的复杂度是O(N*N)。
// 整体的复杂度为O(N^3)

class Solution {
public:
    int minCut(string s) {
    	if(s.empty())
    		return 0;

    	arr_.resize(s.length());
    	for(vector<char>& v: arr_)
    		v.resize(s.length());

    	for(int i = 0; i < s.length(); ++i)
    	{
    		for(int j = i; j < s.length(); ++j)
    		{
    			arr_[i][j] = IsPalindrome(s, i, j);
    			//cout<<"arr["<<i<<"]["<<j<<"]="<<int(arr_[i][j])<<"\n";
    		}
    	}

    	vector<int> result;
    	result.resize(s.length(), std::numeric_limits<int>::max());

    	for(int i = 0; i < s.length(); ++i)
    	{
    		if(arr_[0][i])
    			result[i] = 1;

    		for(int j = 0; j < i; ++j)
    		{
    			if(arr_[j+1][i] == 1)
    				result[i] = std::min(result[i], result[j] + arr_[j+1][i]);
    		}
    		//cout<<"result["<<i<<"]="<<result[i]<<"\n";
    	}

    	return result.back() - 1;
    }
private:
    bool IsPalindrome(const string& s, int i, int j)
    {
    	const char* p1 = &s[0] + i;
    	const char* p2 = &s[0] + j;
    	while(p1 <= p2)
    	{
    		if(*p1++ != *p2--)
    			return false;
    	}
    	return true;
    }
private:
    vector<vector<char>> arr_;//数组, arr[i][j]为1表示字符串str[i..j]为回文，0<=i<=j<len(str)
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	Solution* ps = new Solution;
	auto&& result = ps->minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp");
	cout<<"ret="<<result<<"\n";
	auto&& ret = ps->minCut("abcdefggfedcba");
	cout<<"ret="<<ret<<"\n";
	ret = ps->minCut("bbaa");
	cout<<"ret="<<ret<<"\n";
	return 0;
}




