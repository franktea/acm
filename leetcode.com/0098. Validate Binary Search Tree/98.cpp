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
// 每个节点的所有子节点的最大、最小值时时刻刻都记下来，
// 如果某个节点N的左节点L不为空，则N节点的值应该大于L的最大值；
// 如果某个节点N的右节点R不为空，则N节点的值应该小于R的最小值；

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
    bool PostDFS(TreeNode* root, int& min_value, int& max_value)
	{
    	if(!root->left && !root->right) // leaf
    	{
    		max_value = root->val;
    		min_value = root->val;
    		return true;
    	}

    	int min_tmp_left;
    	int max_tmp_left;
    	if(root->left)
    	{
    		if(! (root->left->val < root->val))
    			return false;

    		if(!PostDFS(root->left, min_tmp_left, max_tmp_left))
    			return false;

    		if(! (max_tmp_left < root->val))
    			return false;
    	}
    	else
    	{
    		min_tmp_left = max_tmp_left = root->val;
    	}

    	int min_tmp_right;
    	int max_tmp_right;
    	if(root->right)
    	{
    		if(! (root->right->val > root->val))
    			return false;

    		if(!PostDFS(root->right, min_tmp_right, max_tmp_right))
    			return false;

    		if(! (min_tmp_right > root->val))
    			return false;
    	}
    	else
    	{
    		min_tmp_right = max_tmp_right = root->val;
    	}

    	min_value = std::min(min_tmp_left, min_tmp_right);
    	max_value = std::max(max_tmp_right, max_tmp_right);

    	return true;
	}
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

TEST_CASE("TEST BST")
{
	using tn = TreeNode;
	Solution* ps = new Solution;
	TreeNode* t;

	t = new tn(5, new tn(1), new tn(4, new tn(3), new tn(6)));
	REQUIRE(! ps->isValidBST(t));

	t = new tn(2, new tn(1), new tn(3));
	REQUIRE(ps->isValidBST(t));

	t = new tn(3, new tn(1, new tn(0), new tn(2, nullptr, new tn(3))),
			      new tn(5, new tn(4), new tn(6)));
	REQUIRE(! ps->isValidBST(t));

	t = new tn(10, new tn(5),
				   new tn(15, new tn(6), new tn(20)));
	REQUIRE(! ps->isValidBST(t));
}



