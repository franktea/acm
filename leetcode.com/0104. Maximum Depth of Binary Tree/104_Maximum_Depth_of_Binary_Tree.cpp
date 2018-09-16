/*
 * 104_Maximum_Depth_of_Binary_Tree.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: frank
 */

#include <iostream>
#include <algorithm>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

