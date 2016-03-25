//
//  206_ReverseLinkedList.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _06_ReverseLinkedList_h
#define _06_ReverseLinkedList_h


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* newSecond = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newSecond;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p = head;
        while(p->next)
            p = p->next;
        while(head != p){
            ListNode* next = head->next;
            head->next = p->next;
            p->next = head;
            head = next;
        }
        return p;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* nh = NULL;
        ListNode* p = head;
        
        while(p){
            ListNode* next = p->next;
            if(!nh){
                nh = p;
                nh->next = NULL;
            }
            else{
                p->next = nh;
                nh = p;
            }
            p = next;
        }
        return nh;
    }};


#endif /* _06_ReverseLinkedList_h */
