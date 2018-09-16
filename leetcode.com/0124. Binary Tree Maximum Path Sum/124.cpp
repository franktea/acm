/*
 * 124.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: frank
 */
#include <algorithm>
#include <iostream>
using namespace std;

// 求任意两个节点之间的路径和的最大值，看来是要把所有两个节点之间的距离全部算出来，然后再找最大的过程。
// 实际上可用寻找经过某个父节点的最大和的方法，如果某个节点的子节点的最大和为负数，直接去掉即可

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
    	if(!root) return 0;
    	max_sum_ = root->val;
    	Recurse(root);
    	return max_sum_;
    }
public:
    int Recurse(TreeNode* root)
    {
    	if(!root->left && !root->right) // leaf
    		return root->val;

    	max_sum_ = std::max(max_sum_, root->val);

    	int left = 0;
    	int right = 0;
    	if(root->left)
    	{
    		left = Recurse(root->left);
    		max_sum_ = std::max(max_sum_, left);
    	}
    	if(root->right)
    	{
    		right = Recurse(root->right);
    		max_sum_ = std::max(max_sum_, right);
    	}

    	int ret = max(max(root->val, root->val + left), root->val + right); // 当前节点的子节点的最大和
    	max_sum_ = max(max_sum_, max(ret, root->val + left + right)); // root->val + left + right为经过当前节点的路径的最大和
    	return ret;;
    }
private:
    int max_sum_;
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	using tn = TreeNode;
	tn* root = //new tn(-10, new tn(9), new tn(20, new tn(15), new tn(7)));
			//new tn(1, new tn(2, new tn(3)));
			//new tn(-2,new tn(-1));
			new tn(5, new tn(4, new tn(11, new tn(7), new tn(2))), new tn(8, new tn(13), new tn(4, nullptr, new tn(1))));
	Solution* ps = new Solution;
	int ret = ps->maxPathSum(root);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



