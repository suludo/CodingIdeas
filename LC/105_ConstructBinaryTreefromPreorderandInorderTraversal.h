//
//  105_ConstructBinaryTreefromPreorderandInorderTraversal.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _05_ConstructBinaryTreefromPreorderandInorderTraversal_h
#define _05_ConstructBinaryTreefromPreorderandInorderTraversal_h


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
    TreeNode* helper(vector<int> & pre, vector<int> & in, int ps, int is, int len, unordered_map<int, int> &mp){
        if(len<=0) return NULL;
        int rootVal = pre[ps];
        int rootIndexIn = mp.find(rootVal)==mp.end() ? -1:mp[rootVal];
        //for(int i=0; i<len; i++){
        //    if(in[is+i]==rootVal){
        //        rootIndexIn = is+i;
        //        break;
        //    }
        //}
        if(rootIndexIn<0) return NULL;
        TreeNode* root = new TreeNode(rootVal);
        TreeNode* l = helper(pre, in, ps+1, is, rootIndexIn-is, mp);
        TreeNode* r = helper(pre, in, ps+rootIndexIn-is+1, rootIndexIn+1, len-rootIndexIn+is-1, mp);
        root->left = l;
        root->right = r;
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;
        if(preorder.size() != inorder.size()) return NULL;
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;
        TreeNode* ret = helper(preorder, inorder, 0, 0, preorder.size(), mp);
        return ret;
    }
};
#endif /* _05_ConstructBinaryTreefromPreorderandInorderTraversal_h */
