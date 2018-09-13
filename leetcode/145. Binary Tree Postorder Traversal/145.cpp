/*
 * 145.cpp
 *
 *  Created on: Sep 13, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> result;
    	if(!root) return result;

    	std::stack<std::pair<bool, TreeNode*>> s;
    	s.push({false, root});
    	while(!s.empty())
    	{
    		std::pair<bool, TreeNode*> p = s.top();
    		s.pop();
    		if(!p.first)
    		{
    			s.push({true, p.second});
    			if(p.second->right)
    				s.push({false, p.second->right});
    			if(p.second->left)
    				s.push({false, p.second->left});
    		}
    		else
    		{
    			result.push_back(p.second->val);
    		}
    	}

    	return result;
    }
};

int main()
{
	using tn = TreeNode;
	tn* root = new tn(1, new tn(2, new tn(4), new tn(5)),
						 new tn(3, new tn(6), new tn(7)));
	Solution* ps = new Solution;
	vector<int> v= ps->postorderTraversal(root);
	for(int i: v)
		cout<<i<<", ";
	cout<<"\n";
	return 0;
}



