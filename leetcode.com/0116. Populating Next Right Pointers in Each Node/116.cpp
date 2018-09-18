/*
 * 116.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */
#include <iostream>
#include <queue>

using namespace std;

// 用了广度优先，空间复杂度不符合题目要求。题目要求用递归，或者常量空间。

//Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
 	TreeLinkNode *left, *right, *next;
 	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(!root) return;

    	queue<std::pair<int, TreeLinkNode*>> bfs;
    	bfs.push({0, root});
    	while(!bfs.empty())
    	{
    		auto p = bfs.front();
    		bfs.pop();
    		if(bfs.empty() || bfs.front().first != p.first)
    			p.second->next = nullptr;
    		else
    			p.second->next = bfs.front().second;

    		if(p.second->left)
    			bfs.push({p.first+1, p.second->left});
    		if(p.second->right)
    			bfs.push({p.first+1, p.second->right});
    	}
    }
};





