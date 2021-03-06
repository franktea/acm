/*
 * 101_Symmetric_Tree.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: frank
 */
#include <iostream>

using namespace std;

// 做对了，对递归的理解加深了

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool cmp(TreeNode* node1, TreeNode* node2)
	{
		if(!node1 && !node2) return true;

		if(!node1 ^ !node2) return false;

		if(node1->val != node2->val) return false;

		return cmp(node1->left, node2->right) &&
				cmp(node1->right, node2->left);
	}

    bool isSymmetric(TreeNode* root)
    {
    	if(!root) return true;

    	return cmp(root->left, root->right);
    }
};

int main()
{
	return 0;
}



