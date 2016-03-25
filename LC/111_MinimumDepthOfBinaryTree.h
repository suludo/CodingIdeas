//
//  111_MinimumDepthOfBinaryTree.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _11_MinimumDepthOfBinaryTree_h
#define _11_MinimumDepthOfBinaryTree_h



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        if(root->left && root->right) return 1+min(minDepth(root->left), minDepth(root->right));
        return 1+ (root->left ? minDepth(root->left):minDepth(root->right));
    }
};


#endif /* _11_MinimumDepthOfBinaryTree_h */
