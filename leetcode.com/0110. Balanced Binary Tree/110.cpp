/*
 * 110.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	bool result = true;
    	DFS(root, result);
    	return result;
    }
private:
    int DFS(TreeNode* root, bool& result)
    {
    	if(!root)
    		return 0;

    	int l = DFS(root->left, result);
    	if(! result)
    		return l;
    	int r = DFS(root->right, result);
    	if(! result)
    		return r;

    	if(abs(l - r) > 1)
    		result = false;

    	return 1 + std::max(l, r);
    }
};

int main()
{
	return 0;
}

