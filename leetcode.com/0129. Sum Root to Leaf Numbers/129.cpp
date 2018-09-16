/*
 * 129.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
    	if(!root) return 0;
    	DFS(root, 0);
    	return std::accumulate(numbers_.begin(), numbers_.end(), 0);
    }
public:
    void DFS(TreeNode* root, int number)
    {
    	number = number * 10 + root->val;
    	if(!root->left && !root->right)
    	{
    		numbers_.push_back(number);
    		return;
    	}

    	if(root->left)
    		DFS(root->left, number);
    	if(root->right)
    		DFS(root->right, number);
    }
private:
    vector<int> numbers_;
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	return 0;
}

