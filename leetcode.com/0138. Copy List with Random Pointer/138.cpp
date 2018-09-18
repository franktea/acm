/*
 * 138.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */
#include <iostream>
#include <map>

using namespace std;

// 用map保存random指针的映射，提交不通过。这题很无聊，暂时不想找原因。

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x, RandomListNode* n = nullptr) : label(x), next(n), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(!head) return nullptr;
    	RandomListNode* h = head;
    	map<RandomListNode*, RandomListNode*> pointer_map;
    	RandomListNode* ret = new RandomListNode(head->label);
    	pointer_map.insert({head, ret});
    	RandomListNode* head2 = ret;
    	head = head->next;
    	while(head)
    	{
    		RandomListNode* p = new RandomListNode(head->label);
    		pointer_map.insert({head, p});
    		head2->next = p;
    		head2 = head2->next;
    		head = head->next;
    	}

    	RandomListNode* h2 = ret;
    	while(h)
    	{
    		h2->random = pointer_map[h];
    		h2 = h2->next;
    		h = h->next;
    	}

    	return ret;
    }
};

int main()
{
	using ln = RandomListNode;
	ln* head = new ln(1, new ln(2));
	head->random = head;
	head->next->random = head;
	Solution* ps = new Solution;
	ln* h = ps->copyRandomList(head);
	cout<<":::::"<<h->random->label<<"\n";
	while(h)
	{
		cout<<h->label<<", ";
		h = h->next;
	}
	cout<<"\n";
	return 0;
}



