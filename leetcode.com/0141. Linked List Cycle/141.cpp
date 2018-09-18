/*
 * 141.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: frank
 */


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p1 && p2)
        {
            p1 = p1->next;
            p2 = p2->next;
            if(!p2)
                return false;
            p2 = p2->next;
            if(p1 == p2)
                return true;
        }

        return false;
    }
};

