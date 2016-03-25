//
//  235_LowestCommonAncestorOfABinarySearchTree.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _35_LowestCommonAncestorOfABinarySearchTree_h
#define _35_LowestCommonAncestorOfABinarySearchTree_h


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
        if(!root || root==p || root==q) return root;
        TreeNode* lca_l = lowestCommonAncestor(root->left, p, q);
        TreeNode* lca_r = lowestCommonAncestor(root->right, p, q);
        if(lca_l && lca_r) return root;
        return lca_l ? lca_l:lca_r;
    }
};




//Find by value in BST

/* Function to find LCA of n1 and n2. The function assumes that both
 n1 and n2 are present in BST */
/*
struct node *lca(struct node* root, int n1, int n2)
{
    while (root != NULL)
    {
        // If both n1 and n2 are smaller than root, then LCA lies in left
        if (root->data > n1 && root->data > n2)
            root = root->left;
        
        // If both n1 and n2 are greater than root, then LCA lies in right
        else if (root->data < n1 && root->data < n2)
            root = root->right;
        
        else break;
    }
    return root;
}
 */

#endif /* _35_LowestCommonAncestorOfABinarySearchTree_h */
