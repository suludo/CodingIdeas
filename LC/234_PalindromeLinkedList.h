//
//  234_PalindromeLinkedList.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _34_PalindromeLinkedList_h
#define _34_PalindromeLinkedList_h


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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *s = head; //slow
        ListNode *f = head; //fast
        //ListNode* p = head;
        while(s && f){
            if(!f->next) break;
            f = f->next;
            if(!f->next) break;
            f = f->next;
            //CAN'T DO THIS! f is used as the tail in the follwing codes
            //if(!f->next || !f->next->next) break;
            s = s->next;
        }
        
        //now s is the pre of second half
        //and f is the tail
        //reverse second half
        while(s->next!=f){
            ListNode* tmp = s->next->next;
            s->next->next = f->next;
            f->next = s->next;
            s->next = tmp;
        }
        //compare
        while(s->next){
            if(head->val != s->next->val) return false;
            s = s->next;
            head = head->next;
        }
        // while(s->next){
        //     if(p->val != s->next->val) return false;
        //     s = s->next;
        //     p = p->next;
        // }
        return true;
    }
};


#endif /* _34_PalindromeLinkedList_h */
