/*
 * 114.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* l=nullptr, TreeNode* r=nullptr) : val(x), left(l), right(r) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
    	if(!root) return;

    	DFS(root);
    }
private:
    TreeNode* DFS(TreeNode* root) // 返回值为最左下角或最右下角的节点
    {
    	if(!root->left && !root->right)
    		return root;

    	TreeNode* ret = nullptr;
    	if(root->right)
    		ret = DFS(root->right);

    	if(root->left)
    	{
    		TreeNode* l = DFS(root->left);
    		l->right = root->right;
    		if(!ret) ret = l;
    		root->right = root->left;
    		root->left = nullptr;
    	}

    	return ret;
    }
};

int main()
{
	return 0;
}



