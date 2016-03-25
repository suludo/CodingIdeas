//
//  203_RemoveLinkedListElements.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _03_RemoveLinkedListElements_h
#define _03_RemoveLinkedListElements_h



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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* pre = dummy;
        while(pre->next){
            if(pre->next->val == val)
                pre->next = pre->next->next;
            else
                pre = pre->next;
        }
        
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
    
    ListNode* removeElements1(ListNode* head, int val) {
        ListNode* nh = NULL;
        ListNode* prev = NULL;
        
        while(head){
            if(head->val != val){
                if(!nh)
                    nh = head;
                else
                    prev->next = head;
                prev = head;
            }
            head = head->next;
        }
        if(nh) prev->next = NULL;
        return nh;
    }
};



#endif /* _03_RemoveLinkedListElements_h */
