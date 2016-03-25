//
//  199_BinaryTreeRightSideView.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _99_BinaryTreeRightSideView_h
#define _99_BinaryTreeRightSideView_h


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
    void helper(TreeNode* root, int h, vector<int>& res){
        if(!root) return;
        if(h>=res.size())
            res.push_back(root->val);
        helper(root->right, h+1, res);
        helper(root->left, h+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        helper(root, 0, ret);
        return ret;
    }
};


#endif /* _99_BinaryTreeRightSideView_h */
