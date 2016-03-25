//
//  236_LowestCommonAncestorOfABinaryTree.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _36_LowestCommonAncestorOfABinaryTree_h
#define _36_LowestCommonAncestorOfABinaryTree_h


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p==q) return NULL;
        if(root==p || root==q) return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l&&r)
            return root;
        return l ? l:r;
        
    }
};


class Solution {
    vector<TreeNode*> pPath, qPath;
    void dfs(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode*> &path){
        if(!root) return;
        if(!pPath.empty() && !qPath.empty()) return;
        path.push_back(root);
        if(pPath.empty() && root == p)
            pPath = path;
        if(qPath.empty() && root == q)
            qPath = path;
        dfs(root->left, p, q, path);
        dfs(root->right, p, q, path);
        path.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        TreeNode* ret = NULL;
        dfs(root, p, q, path);
        if(pPath.empty() || qPath.empty()) return pPath.empty() ? q:p;
        int i=0, len=min(pPath.size(), qPath.size());
        while(i<len && pPath[i]==qPath[i]){
            ret = pPath[i];
            i++;
        }
        return ret;
    }
};

#endif /* _36_LowestCommonAncestorOfABinaryTree_h */
