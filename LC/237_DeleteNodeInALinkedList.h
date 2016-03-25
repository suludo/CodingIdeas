//
//  237_DeleteNodeInALinkedList.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _37_DeleteNodeInALinkedList_h
#define _37_DeleteNodeInALinkedList_h

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
    void deleteNode1(ListNode* node) {
        ListNode* tmp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete tmp;
    }
    
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        *node = *temp;
        delete temp;
    }
};


#endif /* _37_DeleteNodeInALinkedList_h */
