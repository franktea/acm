/*
 * 24.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>

using namespace std;

// 用了3个临时变量

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	ListNode* p1 = head;
    	ListNode* last = nullptr; // 用两个指针p1 p2一次遍历，用last记录p1的上一个节点
    	while(p1 && p1->next)
    	{
    		ListNode* p2 = p1->next;
    		p1->next = p2->next;
    		p2->next = p1;
    		if(last)
    			last->next = p2;

    		if(head == p1)
    			head = p2;

    		last = p1;
    		p1 = p1->next;
    	}

    	return head;
    }
};

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

int main()
{
	ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
	Solution* ps = new Solution;
	ListNode* n = ps->swapPairs(l1);
	while(n)
	{
		cout<<n->val<<", ";
		n = n->next;
	}
	cout<<"\n";
	return 0;
}



