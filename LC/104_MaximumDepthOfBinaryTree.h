//
//  104_MaximumDepthOfBinaryTree.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _04_MaximumDepthOfBinaryTree_h
#define _04_MaximumDepthOfBinaryTree_h



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
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};

#endif /* _04_MaximumDepthOfBinaryTree_h */
