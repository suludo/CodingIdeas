//
//  109_CovertSortedListToBinarySearchTree.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _09_CovertSortedListToBinarySearchTree_h
#define _09_CovertSortedListToBinarySearchTree_h

//pay attn to how the head is referenced

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(ListNode* &head, int start, int end){
        if(!head || start>end) return NULL;
        
        int mid = start+(end-start)/2;
        TreeNode* l = helper(head, start, mid-1);
        TreeNode* parent = new TreeNode(head->val);
        parent->left = l;
        head = head->next;
        parent->right = helper(head, mid+1, end);
        return parent;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode* p = head;
        int len =0;
        while(p){
            len++;
            p = p->next;
        }
        return helper(head, 0, len-1);
    }
};
#endif /* _09_CovertSortedListToBinarySearchTree_h */
