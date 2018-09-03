/*
 * 21.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: frank
 */
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* head = nullptr;
    	ListNode* tail = nullptr;

    	auto f = [&head, &tail](ListNode* p) {
    		if(tail)
    		{
    			tail->next = p;
    		}

    		tail = p;

    		if(!head)
    			head = tail;
    	};

    	while(l1 || l2)
    	{
    		ListNode* p1 = l1;
    		ListNode* p2 = l2;

    		if(p1 && p2)
    		{
    			if(p1->val < p2->val)
    			{
    				l1 = p1->next;
    				p1->next = nullptr;
    				f(p1);
    			}
    			else
    			{
    				l2 = p2->next;
    				p2->next = nullptr;
    				f(p2);
    			}
    		}
    		else if(p1) // p1 != null && p2 = null
    		{
				l1 = p1->next;
				p1->next = nullptr;
				f(p1);
    		}
    		else if(p2) // p1 == null && p2 != null
    		{
				l2 = p2->next;
				p2->next = nullptr;
				f(p2);
    		}
    	}

    	return head;
    }
};

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

int main()
{
	ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
	ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
	Solution* ps = new Solution;
	ListNode* n = ps->mergeTwoLists(l1, l2);
	while(n)
	{
		cout<<n->val<<", ";
		n=n->next;
	}
	cout<<"\n";
	return 0;
}
