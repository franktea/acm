/*
 * 23.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: frank
 */

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

// 将所有的节点全部取出来，放在multimap里面去排序。比较浪费空间的解法，下次再试试每次取一个然后再排序的做法

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	std::multimap<int, ListNode*> all;
    	for(ListNode* n: lists)
    	{
    		while(n)
    		{
    			all.insert(std::make_pair(n->val, n));
    			n = n->next;
    		}
    	}

    	ListNode* head = nullptr;
    	ListNode* tail = nullptr;

    	if(all.empty())
    		return head;

    	while(!all.empty())
    	{
    		auto it = all.begin();
    		all.erase(it);
    		it->second->next = nullptr;
    		if(! tail)
    			tail = it->second;
    		else
    		{
    			tail->next = it->second;
    			tail = tail->next;
    		}

    		if(!head)
    			head = tail;
    	}

    	return head;
    }
};

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

int main()
{
	ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
	ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
	ListNode* l3 = new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(8))));
	Solution* ps = new Solution;
	vector<ListNode*> v = {l1, l2, l3};
	ListNode* n = ps->mergeKLists(v);
	while(n)
	{
		cout<<n->val<<", ";
		n=n->next;
	}
	cout<<"\n";
	return 0;
}
