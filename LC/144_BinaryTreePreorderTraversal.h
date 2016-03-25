//
//  144_BinaryTreePreorderTraversal.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _44_BinaryTreePreorderTraversal_h
#define _44_BinaryTreePreorderTraversal_h


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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> parents;
        vector<int> res;
        if(!root) return res;
        parents.push(root);
        
        while(!parents.empty()){
            TreeNode* tmp = parents.top();
            res.push_back(tmp->val);
            parents.pop();
            if(tmp->right)
                parents.push(tmp->right);
            if(tmp->left)
                parents.push(tmp->left);
        }
        
        return res;
    }

    void ptHelper(TreeNode* root, vector<int> & ret){
        if(!root)
            return;
        ret.push_back(root->val);
        ptHelper(root->left, ret);
        ptHelper(root->right, ret);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        ptHelper(root, ret);
        return ret;
    }
};

#endif /* _44_BinaryTreePreorderTraversal_h */
