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
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
    	if(!head) return nullptr;
    	Node* h = head;
    	map<Node*, Node*> pointer_map; // 用map没有任何问题，只是之前的对应关系没搞对
    	Node* ret = new Node(head->val);
    	pointer_map.insert({head, ret});
    	Node* head2 = ret;
    	head = head->next;
    	while(head)
    	{
    		Node* p = new Node(head->val);
    		pointer_map.insert({head, p});
    		head2->next = p;
    		head2 = head2->next;
    		head = head->next;
    	}

    	Node* h2 = ret;
    	while(h)
    	{	
			if(h->random)
    			h2->random = pointer_map[h->random];

    		h2 = h2->next;
    		h = h->next;
    	}

    	return ret;
    }
};

int main()
{
	return 0;
}



