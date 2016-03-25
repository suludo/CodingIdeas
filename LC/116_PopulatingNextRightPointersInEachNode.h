//
//  116_PopulatingNextRightPointersInEachNode.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _16_PopulatingNextRightPointersInEachNode_h
#define _16_PopulatingNextRightPointersInEachNode_h


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        
        TreeLinkNode* p = root;
        TreeLinkNode* nextStart = NULL;
        TreeLinkNode* prevNode = NULL;
        while(p){
            if(!nextStart){
                while(p && !p->left && !p->right && p->next)
                    p = p->next;
                if(p) nextStart = p->left ? p->left : p->right;
            }
            
            if(p->left){
                if(prevNode) prevNode->next = p->left;
                if(p->right) {
                    p->left->next = p->right;
                    prevNode = p->right;
                }
                else prevNode = p->left;
            }
            else if(p->right){
                if(prevNode) prevNode->next = p->right;
                prevNode = p->right;
            }
            
            if(!p->next){
                if(!nextStart) break;
                prevNode = NULL;
                p = nextStart;
                nextStart = NULL;
            }
            else p = p->next;
        }
    }
};

#endif /* _16_PopulatingNextRightPointersInEachNode_h */
