/*
 * 107.cpp
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> v;
    	if(!root)
    		return v;

    	int last_level = 0;
    	v.push_back(vector<int>());
    	std::queue<std::pair<int, TreeNode*>> q; // level->node
    	q.push(std::make_pair(0, root));
    	while(!q.empty())
    	{
    		std::pair<int, TreeNode*> p = q.front();
    		q.pop();
    		int level = p.first;
    		TreeNode* tn = p.second;
    		if(level != last_level)
    		{
    			v.push_back(vector<int>());
    			last_level = level;
    		}
    		v.back().push_back(tn->val);
    		if(tn->left)
    			q.push(std::make_pair(level+1, tn->left));
    		if(tn->right)
    			q.push(std::make_pair(level+1, tn->right));
    	}

    	std::reverse(v.begin(), v.end());
    	return v;
    }
};
static int fast = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	using tn = TreeNode;
	tn* root = new tn(3, new tn(9), new tn(20, new tn(15), new tn(7)));
	Solution* ps = new Solution;
	auto&& vv = ps->levelOrderBottom(root);
	for(auto&& v: vv)
	{
		for(int i: v)
			cout<<i<<", ";
		cout<<"\n";
	}
	return 0;
}



