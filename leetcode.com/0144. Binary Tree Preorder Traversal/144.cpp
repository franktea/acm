/*
 * 144.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> ret;
    	if(!root) return ret;
    	stack<TreeNode*> s;
    	s.push(root);
    	while(!s.empty())
    	{
    		TreeNode* t = s.top();
    		s.pop();
    		ret.push_back(t->val);
    		if(t->right)
    			s.push(t->right);
    		if(t->left)
    			s.push(t->left);
    	}

    	return ret;
    }
};

int main()
{
	return 0;
}



