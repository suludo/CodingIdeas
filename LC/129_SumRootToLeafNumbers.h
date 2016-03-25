//
//  129_SumRootToLeafNumbers.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _29_SumRootToLeafNumbers_h
#define _29_SumRootToLeafNumbers_h


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
    void dfs(TreeNode *root, int64_t curSum, int64_t &res){
        if(!root) return;
        curSum = curSum*10 + root->val;
        if(!root->left && !root->right){
            res += curSum;
            return;
        }
        dfs(root->left, curSum, res);
        dfs(root->right, curSum, res);
    }
    int sumNumbers(TreeNode* root) {
        int64_t ret = 0;
        dfs(root, 0, ret);
        return ret;
    }
};

#endif /* _29_SumRootToLeafNumbers_h */
