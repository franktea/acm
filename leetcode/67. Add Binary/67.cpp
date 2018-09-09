/*
 * 67.cpp
 *
 *  Created on: Sep 9, 2018
 *      Author: frank
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) swap(a, b);
        if(a.empty()) return "";
        if(b.empty()) return a;

        string result;
        int left = 0;
        for(int index = 1; index <= b.size(); ++index)
        {
        		int index_a = a.size() - index;
        		int index_b = b.size() - index;
            int va = a[index_a] - '0';
            int vb = b[index_b] - '0';
            //cout<<"i="<<i<<", va="<<va<<", vb="<<vb<<"\n";
            int value = va + vb + left;
            int v = value % 2;
            left = value / 2;
            result.insert(0, 1, '0' + v);
            //cout<<"result="<<result<<"\n";
        }
        for(int index = b.size(); index < int(a.size()); ++index)
        {
        		int index_a = a.size() - index - 1;
            int va = a[index_a] - '0';
            //cout<<"a["<<index_a<<"]="<<va<<"\n";
            int value = va + left;
            int v = value % 2;
            left = value / 2;
            result.insert(0, 1, '0' + v);
            //cout<<"result:"<<result<<"\n";
        }
        if(left > 0)
            result.insert(0, 1, '0' + left);

        return result;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	string a = "100";
	string b = "110010";
	Solution* ps = new Solution;
	string ret = ps->addBinary(a, b);
	cout<<"ret="<<ret<<"\n";
	return 0;
}

