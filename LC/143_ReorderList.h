//
//  143_ReorderList.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _43_ReorderList_h
#define _43_ReorderList_h



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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        ListNode* p1 = head;
        ListNode* p2 = head;
        // while(p1 && p2){
        //     p2 = p2->next;
        //     if(!p2) break;
        //     p2 = p2->next;
        //     if(!p2) break;
        //     p1 = p1->next;
        // }
        while(p2->next && p2->next->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        //reverse the second half
        ListNode* p = p1->next->next;
        ListNode* tail = p1->next;
        while(p){
            p2 = p->next;
            ListNode* tmp = p1->next;
            p1->next = p;
            p->next = tmp;
            p = p2;
        }
        tail->next = NULL;
        //do the re-assembly
        p = head;
        p2 = p1->next; //head of second half, LEQ first half
        p1->next = NULL;
        //p1 = NULL; //as prev
        
        while(p2){
            ListNode* tmp = p->next;
            ListNode* tmp2 = p2->next;
            p->next = p2;
            p2->next = tmp;
            
            p2 = tmp2;
            p = tmp;
        }
    }
    
};

#endif /* _43_ReorderList_h */
