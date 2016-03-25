//
//  230_KthSmallestElementInBST.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _30_KthSmallestElementInBST_h
#define _30_KthSmallestElementInBST_h

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    bool helper(TreeNode* root, int &index, int k, int &res){
        if(!root /*|| index > k*/) return false;
        if(helper(root->left, index, k, res))
            return true;
        index++;
        if(index==k){
            res = root->val;
            return true;
        }
        return helper(root->right, index, k, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int index = 0;
        int res = 0;
        helper(root, index, k, res);
        return res;
    }
};



class Solution {
public:
    void dfs(TreeNode* root, int &cur, int &res, int k){
        if(!root) return;
        dfs(root->left, cur, res, k);
        ++cur;
        if(cur==k){
            res = root->val;
            return;
        }
        dfs(root->right, cur, res, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = 0, cur = 0;
        dfs(root ,cur, res, k);
        return res;
    }
};


#endif /* _30_KthSmallestElementInBST_h */
