//
//  110_BalancedBinaryTree.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _10_BalancedBinaryTree_h
#define _10_BalancedBinaryTree_h


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
    int treeDepth(TreeNode* node){
        if(!node) return 0;
        
        return 1+max(treeDepth(node->left), treeDepth(node->right));
    }
    bool isBalanced(TreeNode *root) {
        if(!root) return true;
        
        int dl = treeDepth(root->left);
        int dr = treeDepth(root->right);
        if(abs(dl-dr)<=1)
            return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }
};

#endif /* _10_BalancedBinaryTree_h */
