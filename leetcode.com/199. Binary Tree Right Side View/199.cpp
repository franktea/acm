/*
 * 199.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

// 用bfs，没啥好说的

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> result;

    	if(!root) return result;

    	std::deque<std::pair<int, TreeNode*>> bfs;
    	bfs.push_back({0, root});
    	while(!bfs.empty())
    	{
    		auto p = bfs.front();
    		bfs.pop_front();
    		if(bfs.empty() || bfs[0].first != p.first)
    		{
    			result.push_back(p.second->val);
    		}
    		if(p.second->left)
    			bfs.push_back({1+p.first, p.second->left});
    		if(p.second->right)
    			bfs.push_back({1+p.first, p.second->right});
    	}

    	return result;
    }
};

int main()
{
	using tn = TreeNode;
	Solution* ps = new Solution;
	TreeNode* root = new tn(1, new tn(2, nullptr, new tn(5)),
			new tn(3, nullptr, new tn(4)));
	vector<int> v = ps->rightSideView(root);
	for(int i: v)
		cout<<i<<", ";
	cout<<"\n";
	return 0;
}


