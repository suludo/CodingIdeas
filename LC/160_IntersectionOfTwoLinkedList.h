//
//  160_IntersectionOfTwoLinkedList.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _60_IntersectionOfTwoLinkedList_h
#define _60_IntersectionOfTwoLinkedList_h


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        
        ListNode* pa = headA;
        ListNode* pb = headB;
        while(pa && pb){
            if(pa==pb) return pa;
            pa = pa->next;
            pb = pb->next;
            
            if(!pa && !pb) return NULL;
            if(!pa) pa = headB;
            if(!pb) pb = headA;
            
        }
        return NULL;
    }
};

#endif /* _60_IntersectionOfTwoLinkedList_h */
