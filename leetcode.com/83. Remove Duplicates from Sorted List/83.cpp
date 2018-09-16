/*
 * 83.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: frank
 */
#include <iostream>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head) return head;

    	ListNode* first = head;
    	ListNode* second = first->next;

    	while(second)
    	{
			while(second != nullptr && second->val == first->val)
				second = second->next;

			first->next = second;
			first = second;
			if(second)
				second = second->next;
    	}

    	return head;
    }
};

int main()
{
	return 0;
}



