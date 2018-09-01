/*
 * 2_Add_Two_Numbers.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: frank
 */
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 通过了，但是排名很低，用的是全部重新创建node的方法
// 下次试试尽量采用原有节点的方法

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	explicit ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* header1 = l1;
    	ListNode* header2 = l2;

    	ListNode* result = nullptr;
    	ListNode* tail = nullptr;
    	int tens = 0;
    	while(l1 || l2)
    	{
    		const int v1 = l1 ? l1->val : 0;
    		const int v2 = l2 ? l2->val : 0;
    		const int v = v1 + v2 + tens;

    		ListNode* n = new ListNode(v % 10);
    		tens = v / 10;
    		if(tail)
    			tail->next = n;

    		tail = n;

    		if(!result)
    			result = tail;

    		if(l1) l1 = l1->next;
    		if(l2) l2 = l2->next;
    	}

    	if(tens)
    	{
    		tail->next = new ListNode(tens);
    	}

    	return result;
    }
};

int main()
{
	ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
	ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
	Solution* ps = new Solution;
	ListNode* result = ps->addTwoNumbers(l1, l2);
	while(result)
	{
		cout<<result->val<<",";
		result = result->next;
	}
	cout<<"\n";

	return 0;
}


