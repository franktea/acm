/*
 * 82.cpp
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

    	ListNode* tail = head;
    	std::pair<ListNode*, ListNode*> p = FindFirstTwoEqual(tail);
    	while(p.first && p.second)
    	{
    		for(auto x = p.first; x != p.second->next; x = x->next)
    		{
    			cout<<x->val<<", ";
    		}
    		cout<<"\n";

    		if(head == p.first)
    			head = p.second->next;

    		if(tail == p.first)
    		{
    			tail->next = p.second->next;
    			tail = tail->next;
    		}
    		else
    		{
    			while(tail->next != p.first)
    				tail = tail->next;
    			tail->next = p.second->next;
    			tail = tail->next;
    		}

    		p = FindFirstTwoEqual(tail);
    	}

    	return head;
    }
private:
    std::pair<ListNode*, ListNode*> FindFirstTwoEqual(ListNode* head)
	{
    	if(!head) return {nullptr, nullptr};
    	//cout<<"head::"<<head->val<<"\n";
    	ListNode* first = head;
    	ListNode* second = head->next;
    	if(!second)
    		return {first, nullptr};
    	while(second && first->val != second->val)
    	{
    		first = second;
    		second = second->next;
    	}

    	while(second && second->next && second->val == second->next->val)
    		second = second->next;

    	return {first, second};
	}
};

int main()
{
	using ln = ListNode;
	Solution* ps = new  Solution;
	ListNode* n = new ln(1, new ln(2, new ln(2, new ln (2, new ln(2, new ln(5, new ln(3, new ln(3, new ln(3, new ln(3, new ln(4)))))))))));
	ListNode* ret = ps->deleteDuplicates(n);
	while(ret)
	{
		cout<<ret->val<<", ";
		ret = ret->next;
	}
	cout<<"\n";
	return 0;
}
