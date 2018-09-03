/*
 * 25.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>

using namespace std;

// 把节点全部取出来，存起来，然后再处理

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	vector<vector<ListNode*>> v;
    	ListNode* p = head;
    	int x = 0;
    	while(p)
    	{
    		if(!x)
    			v.push_back(vector<ListNode*>{p});
    		else
    			v[v.size()-1].push_back(p);

    		++x;
    		if(x >= k)
    			x = 0;

    		p = p->next;
    	}

    	ListNode* tail = nullptr;
    	head = nullptr;
    	for(vector<ListNode*>& line: v)
    	{
    		if(line.size() == k)
    			std::reverse(line.begin(), line.end());

    		for(ListNode* n: line)
    		{
    			if(! head)
    				head = n;

    			if(! tail)
    				tail = n;
    			else
    			{
    				tail->next = n;
    				tail = tail->next;
    			}
    		}
    	}

    	if(tail)
    		tail->next = nullptr;

    	return head;
    }
};

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

int main()
{
	ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
	Solution* ps = new Solution;
	ListNode* n = ps->reverseKGroup(l1, 3);
	while(n)
	{
		cout<<n->val<<", ";
		n = n->next;
	}
	cout<<"\n";
	return 0;
}


