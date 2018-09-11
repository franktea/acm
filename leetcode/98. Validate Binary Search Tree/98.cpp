/*
 * 98.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: frank
 */
#include <iostream>
#include <algorithm>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../3rdparty/unit_test/catch2/catch.hpp"
using namespace std;

// 采用后序遍历，从叶子节点向父节点验证，叶子节点向父节点返回当前叶子节点的最大/最小值

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* l=nullptr, TreeNode* r=nullptr) : val(x), left(l), right(r) {}
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	if(!root) return true;
    	int min_value, max_value;
    	return PostDFS(root, min_value, max_value);
    }
private:
    bool PostDFS(TreeNode* root, int& max_left, int& min_right)
	{
    	if(!root->left && !root->right) // leaf
    	{
    		max_left = root->val;
    		min_right = root->val;
    		return true;
    	}

    	int min_left_tmp;
    	int max_left_tmp;
    	if(root->left)
    	{
    		if(! (root->left->val < root->val))
    			return false;

    		if(!PostDFS(root->left, min_left_tmp, max_left_tmp))
    			return false;

    		if(! (max_left_tmp < root->val))
    			return false;

    		min_right = min_left_tmp;
    	}
    	else
    	{
    		min_right = root->val;
    	}

    	int min_right_tmp;
    	int max_right_tmp;
    	if(root->right)
    	{
    		if(! (root->right->val > root->val))
    			return false;

    		if(!PostDFS(root->right, min_right_tmp, max_right_tmp))
    			return false;

    		if(! (min_right_tmp > root->val))
    			return false;

    		max_left = max_right_tmp;
    	}
    	else
    	{
    		max_left = root->val;
    	}

    	cout<<root->val<<", max_left:"<<max_left<<", min_right:"<<min_right<<"\n";
    	return true;
	}
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

TEST_CASE("TEST BST")
{
	using tn = TreeNode;
	Solution* ps = new Solution;
	TreeNode* t;

//	t = new tn(5, new tn(1), new tn(4, new tn(3), new tn(6)));
//	REQUIRE(! ps->isValidBST(t));
//
//	t = new tn(2, new tn(1), new tn(3));
//	REQUIRE(ps->isValidBST(t));

	t = new tn(3, new tn(1, new tn(0), new tn(2, nullptr, new tn(3))),
			      new tn(5, new tn(4), new tn(6)));
	REQUIRE(! ps->isValidBST(t));

//	t = new tn(10, new tn(5),
//				   new tn(15, new tn(6), new tn(20)));
//	REQUIRE(! ps->isValidBST(t));
}



