//
//  112_PathSum.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _12_PathSum_h
#define _12_PathSum_h

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
    bool helper(TreeNode* root, int cur, int sum){
        
        if(!root) return false;
        cur+= root->val;
        if(!root->left && !root->right) return cur==sum;
        return helper(root->left, cur, sum) || helper(root->right, cur, sum);
        
    }
    bool hasPathSum(TreeNode *root, int sum) {
        helper(root, 0, sum);
    }
};

#endif /* _12_PathSum_h */
