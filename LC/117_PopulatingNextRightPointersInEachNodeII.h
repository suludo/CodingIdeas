//
//  117_PopulatingNextRightPointersInEachNodeII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _17_PopulatingNextRightPointersInEachNodeII_h
#define _17_PopulatingNextRightPointersInEachNodeII_h

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
        if(!root)
            return;
        
        root->next = NULL;
        
        TreeLinkNode* p = root;
        TreeLinkNode* nextHead = NULL;
        TreeLinkNode* prev = NULL;
        while(p){
            
            if(!nextHead)
                nextHead = p->left ? p->left:p->right;
            
            if(p->left && p->right){
                if(prev)
                    prev->next = p->left;
                p->left->next = p->right;
                prev = p->right;
            }
            else{
                TreeLinkNode* tmp = p->left ? p->left : p->right;
                
                if(tmp){
                    if(prev)
                        prev->next = tmp;
                    prev = tmp;
                }
            }
            if(p->next)
                p = p->next;
            else{
                p = nextHead;
                nextHead = prev = NULL;
            }
        }
    }
};

#endif /* _17_PopulatingNextRightPointersInEachNodeII_h */
