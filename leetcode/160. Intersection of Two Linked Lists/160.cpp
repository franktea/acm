/*
 * 160.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */

#include <iostream>
#include <algorithm>

using namespace std;

// 先求出两个链表的长度，然后将长的那个链表头移到和短的相同的位置，然后一个个地向后比较。

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	int len_a = Length(headA);
    	int len_b = Length(headB);

    	if(!len_a || !len_b)
    		return nullptr;

    	if(len_a > len_b)
    		Advance(headA, len_a - len_b);
    	else if(len_b > len_a)
    		Advance(headB, len_b - len_a);

    	while(headA && headB)
    	{
    		if(headA == headB)
    			return headA;

    		headA = headA->next;
    		headB = headB->next;
    	}

    	return nullptr;
    }
private:
    void Advance(ListNode*& head, int steps)
    {
    	while(steps--)
    		head = head->next;
    }

    int Length(ListNode* head)
    {
    	int ret = 0;
    	while(head)
    	{
    		++ret;
    		head = head->next;
    	}

    	return ret;
    }
};
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}(); // 加了这个反而更慢了？

