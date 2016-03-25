/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.*/


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
    bool helper(TreeNode* root, int64_t minVal, int64_t maxVal){
        if(!root) return true;
        return (root->val > minVal && root->val<maxVal && helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal));
    }
    bool isValidBST(TreeNode *root) {
        cout<<INT_MIN<<" "<<INT_MAX<<" "<<LLONG_MIN<<" "<<LLONG_MAX<<endl;
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};