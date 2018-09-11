/*
 * 82.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: frank
 */
#include <iostream>
#include <algorithm>

using namespace std;

// 居然打败100%，还存在优化的空间，现在是一个O(2N)的算法，可以改成O(N)，但是思路要足够清醒

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
    	ListNode* last_second = nullptr; // 倒数第二个节点，没这个节点就没法实现本题的功能，现在的解法是每次都去计算该值，而不是存起来的，相当于多了一次遍历
    	std::pair<ListNode*, ListNode*> p = FindFirstTwoEqual(tail);
    	while(p.first && p.second)
    	{
			if(head == p.first)
			{
				head = p.second->next;
			}
			else
			{
				last_second = head;
				while(last_second->next != p.first)
					last_second = last_second->next;

				last_second->next = p.second->next;
			}
			tail = p.second->next;
			p = FindFirstTwoEqual(tail);
    	}

    	return head;
    }
private:
    // 找到连续相等的一串区间，返回该区间的第一个和最后一个
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
static int fast=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

int main()
{
	using ln = ListNode;
	Solution* ps = new  Solution;
	ListNode* n = new ln(1, new ln(2, new ln(2, new ln (2, new ln(2, new ln(3, new ln(3, new ln(3, new ln(3, new ln(4))))))))));
	ListNode* ret = ps->deleteDuplicates(n);
	while(ret)
	{
		cout<<ret->val<<", ";
		ret = ret->next;
	}
	cout<<"\n";
	return 0;
}
