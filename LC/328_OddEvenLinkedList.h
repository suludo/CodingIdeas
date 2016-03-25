//
//  328_OddEvenLinkedList.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _28_OddEvenLinkedList_h
#define _28_OddEvenLinkedList_h

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        bool odd = true;
        ListNode *ho = NULL, *he = NULL; //HEAD of the two rearranged nodes
        ListNode *hhe = head->next;
        ListNode *p = head;
        
        while(p){
            ListNode* next = p->next;
            if(odd){
                if(ho)
                    ho->next = p;
                ho = p;
            }
            else{
                if(he)
                    he->next = p;
                he = p;
            }
            p->next = NULL;
            p = next;
            odd = !odd;
        }
        
        ho->next = hhe;
        return head;
        
    }
};

#endif /* _28_OddEvenLinkedList_h */
