/*
 * 103_Binary_Tree_Zigzag_Level_Order_Traversal.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: frank
 */
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
 	TreeNode *left;
 	TreeNode *right;
 	explicit TreeNode(int x, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
 };

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int>> result;
    	if(!root) return result;

    	queue<std::pair<int, TreeNode*>> q;
    	int depth = 0;
    	result.push_back(vector<int>{});
    	q.push(std::make_pair(depth, root));
    	while(! q.empty())
    	{
    		std::pair<int, TreeNode*> p = q.front();
    		q.pop();
    		if(p.first != depth)
    		{
    			result.push_back(vector<int>{});
    			depth = p.first;
    		}
    		result[result.size()-1].push_back(p.second->val);

    		if(p.second->left)
    			q.push(std::make_pair(p.first + 1, p.second->left));
    		if(p.second->right)
    			q.push(std::make_pair(p.first + 1, p.second->right));
    	}

    	for(size_t i = 0; i < result.size(); ++i)
    	{
    		if(i % 2)
    			std::reverse(result[i].begin(), result[i].end());
    	}

    	return result;
    }
};

int main()
{
	Solution* ps = new Solution;
	TreeNode* root = new TreeNode(1,
			new TreeNode(2, new TreeNode(4)),
			new TreeNode(3, nullptr, new TreeNode(5))
			);
	//TreeNode* root = new TreeNode(3);//, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	auto result = ps->zigzagLevelOrder(root);
	for(const auto& v: result)
	{
		for(int i: v)
			cout<<i<<",";
		cout<<"\n";
	}
	return 0;
}



