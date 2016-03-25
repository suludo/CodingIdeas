//
//  145_BinaryTreePostOrderTraversal.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _45_BinaryTreePostOrderTraversal_h
#define _45_BinaryTreePostOrderTraversal_h



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
    void ptHelper1(TreeNode* root, vector<int> & ret){
        if(!root) return;
        if(!root->left && !root->right){
            ret.push_back(root->val);
        }
        else{
            ptHelper(root->left, ret);
            ptHelper(root->right, ret);
            ret.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        ptHelper(root, res);
        return res;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        vector<int> l = postorderTraversal(root->left);
        vector<int> r = postorderTraversal(root->right);
        
        for(int i=0; i<l.size(); i++)
            ret.push_back(l[i]);
        for(int i=0; i<r.size(); i++)
            ret.push_back(r[i]);
        ret.push_back(root->val);
        return ret;
    }
    
    vector<int> postorderTraversal2(TreeNode *root) {
        vector<int> res;
        if(!root) return res;
        stack <TreeNode*> st;
        TreeNode* prev = NULL;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* t = st.top();
            
            if(!t->left && !t->right){
                st.pop();
                res.push_back(t->val);
                prev = t;
            }
            //prev is non-NULL is important, guarantee that it's recursing from non-empty subtree
            else if(prev && (t->right== prev || (t->right==NULL && t->left==prev))){
                st.pop();
                res.push_back(t->val);
                prev = t;
            }
            else{
                if(t->right)
                    st.push(t->right);
                if(t->left)
                    st.push(t->left);
            }
        }
        
        return res;
    }
    
    
};



#endif /* _45_BinaryTreePostOrderTraversal_h */
