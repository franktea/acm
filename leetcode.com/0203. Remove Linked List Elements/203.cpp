/*
 * 203.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 用两个节点变量，指向连续相邻的两个位置，然后将后一个位置相等的删除。
// 为了不用处理边界情况(就是头指针需要删除的情况)，我突然想到一个绝妙的方法，将一个新的临时节点作为头结点，从而简单了流程。
// 这个想法是不是太有才了？

struct ListNode {
	int val;
 	ListNode *next;
	ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode node(8888); // 临时节点，是什么值根本无所谓，让它来当头结点。
    	node.next = head;

    	ListNode* first = &node;
    	ListNode* second = first->next;

    	while(second)
    	{
    		if(second->val == val)
    		{
    			first->next = second->next;
    		}
    		else
    		{
    			first = second;
    		}

			second = second->next;
    	}

    	return node.next;
    }
};
