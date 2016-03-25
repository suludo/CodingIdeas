//
//  142_LinkedListCycleII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _42_LinkedListCycleII_h
#define _42_LinkedListCycleII_h



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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode* s = head; //slow pointer
        ListNode* f = head; //fast pointer
        
        while(s&&f){
            s = s->next;
            f = f->next;
            if(f) f = f->next;
            if(!f) return NULL;
            if(s==f) break;
        }
        f = head;
        while(s!=f){
            s= s->next;
            f= f->next;
        }
        return s;
    }
};



#endif /* _42_LinkedListCycleII_h */
