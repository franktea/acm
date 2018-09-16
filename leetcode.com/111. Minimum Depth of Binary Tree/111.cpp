/*
 * 111.cpp
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
    int minDepth(TreeNode* root) {
        return MinHeight(root);
    }
private:
    int MinHeight(TreeNode* root)
    {
    	if(!root)
    		return 0;

    	if(!root->left && !root->right)
    		return 1;

    	if(root->left && !root->right)
    		return 1 + MinHeight(root->left);
    	else if(!root->left && root->right)
    		return 1 + MinHeight(root->right);
    	else
    		return 1 + std::min(MinHeight(root->left), MinHeight(root->right));
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	using tn = TreeNode;
	tn* root = new tn(3, new tn(9), new tn(20, new tn(15), new tn(7)));
	Solution* ps = new Solution;
	int ret = ps->minDepth(root);
	cout<<"ret="<<ret<<"\n";
	return 0;
}

