//
//  102_BinaryTreeLevelOrderTraversal.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _02_BinaryTreeLevelOrderTraversal_h
#define _02_BinaryTreeLevelOrderTraversal_h


//pay attn: similar problem can use the h index for simplification
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
    void helper(TreeNode* root, vector<vector<int>> & res, int h){
        if(!root) return;
        if(res.size()<h+1){
            vector<int> tmp(1, root->val);
            res.push_back(tmp);
        }
        else
            res[h].push_back(root->val);
        helper(root->left, res, h+1);
        helper(root->right, res, h+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        helper(root, ret, 0);
        return ret;
    }
};
#endif /* _02_BinaryTreeLevelOrderTraversal_h */
