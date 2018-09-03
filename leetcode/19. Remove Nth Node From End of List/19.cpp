/*
 * 19.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: frank
 */
#include <iostream>

using namespace std;

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(!head) return head;

    	Level(head, n);
    	return head;
    }
private:
    int Level(ListNode*& node, int n)
    {
    	int h = (!node->next) ? 1 : 1 + Level(node->next, n);
    	if(h == n)
    	{
    		node = node->next;
    	}

    	return h;
    }
};

int main()
{
	ListNode* n = new ListNode(1); //, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	Solution* ps = new Solution;
	ListNode* ret = ps->removeNthFromEnd(n, 1);
	while(ret)
	{
		cout<<ret->val<<", ";
		ret = ret->next;
	}
	cout<<"\n";

	return 0;
}



