/*
 * 112.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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
    bool hasPathSum(TreeNode* root, int sum) {
    	if(!root) return false;

    	return Recurve(root, sum);
    }
private:
    bool Recurve(TreeNode* root, int left)
    {
    	left -= root->val;
    	if(!root->left && !root->right) // now it's leaf
    		return 0 == left;

    	if(root->left && Recurve(root->left, left))
    		return true;

    	if(root->right && Recurve(root->right, left))
    		return true;

    	return false;
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	using tn = TreeNode;
	tn* root = new tn(5, new tn(4, new tn(11, new tn(7), new tn(2))), new tn(8, new tn(13), new tn(4, nullptr, new tn(1))));
	Solution* ps = new Solution;
	bool ret = ps->hasPathSum(root, 22);
	cout<<"ret="<<ret<<"\n";
	return 0;
}

