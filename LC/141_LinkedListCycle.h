//
//  141_LinkedListCycle.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _41_LinkedListCycle_h
#define _41_LinkedListCycle_h



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* s = head;
        ListNode* f = head;
        
        while(s&&f){
            s = s->next;
            f = f->next;
            if(f) f = f->next;
            if(s==f) return true;
        }
        return false;
    }
};
le
#endif /* _41_LinkedListCycle_h */
