/*
 * 113.cpp
 *
 *  Created on: Sep 7, 2018
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
TreeNode(int x, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
 };

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	object_sum_ = sum;
    	if(!root)
    		DFS(root, 0);
    	return result_;
    }
private:
    void DFS(TreeNode* root, int sum) // sum 是当前总和
    {
    	if(!root->left && !root->right)
    	{
    		if(sum + root->val == object_sum_)
    		{
    			result_.push_back(path_);
    			result_[result_.size() - 1].push_back(root->val);
    		}
    		return;
    	}

    	path_.push_back(root->val);
    	if(root->left)
    		DFS(root->left, sum + root->val);
    	if(root->right)
    		DFS(root->right, sum + root->val);
    	path_.erase(path_.end() - 1);
    }
private:
    int object_sum_; // 需要查找的和
    vector<vector<int>> result_;
    vector<int> path_; //当前路径
};

int main()
{
	using tn = TreeNode;
	tn* root = new tn(5, new tn(4, new tn(11, new tn(7), new tn(2))), new tn(8, new tn(13), new tn(4, new tn(5), new tn(1))));
	Solution* ps = new Solution;
	vector<vector<int>> vv = ps->pathSum(root, 22);
	for(const vector<int>& v: vv)
	{
		for(int i: v)
		{
			cout<<i<<", ";
		}
		cout<<"\n";
	}
	return 0;
}



