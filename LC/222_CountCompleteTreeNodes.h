//
//  222_CountCompleteTreeNodes.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _22_CountCompleteTreeNodes_h
#define _22_CountCompleteTreeNodes_h



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
    int countNodes1(TreeNode* root) {
        if(!root) return 0;
        int hl = 0;
        int hr = 0;
        TreeNode* l = root;
        TreeNode* r = root;
        while(l){hl++; l = l->left;}
        while(r){hr++; r = r->right;}
        if(hl==hr)
            return (1<<hl)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    //https://leetcode.com/discuss/57025/68ms-c-solution-using-binary-search-with-brief-explanation
    //The thought is simple. We just consider the lowest level of the tree. The left child and right child just divide the tree lower than the current node to 2 part. So what this code do is first check the right most child of the current node's left child. If this child is exist, we know that there may be more nodes on the right side of the tree. So we move the current node to it's right child. And repeat until we reach the lowest level.
    int countNodes2(TreeNode* root) {
        if(!root) return 0;
        TreeNode *temp = root;
        int height = 0, count = 0, level;
        while(temp) {
            temp = temp->left;
            height ++;
        }
        temp = root;
        level = height - 2;
        while(level >= 0) {
            TreeNode *left = temp->left;
            for(int i = 0;i < level;i ++) {
                left = left->right;
            }
            if(left) {
                temp = temp->right;
                count += (1 << level);
            } else temp = temp->left;
            level --;
        }
        if(temp) count ++;
        return (1 << (height - 1)) + count - 1;
    }
    
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
        int countNodes(TreeNode* root) {
            if(!root) return 0;
            TreeNode* p = root;
            int h = 0; //height, #nodes from root to leaf
            while(p){
                ++h;
                p = p->left;
            }
            int ch = 2; //current height/level, start from 2 as the subtree level
            int cnt = 0; // #nodes at h level
            p = root;
            while(ch<=h){
                //current tree, start from its left subtree
                TreeNode *l = p->left;
                // right traverse down to the h level,
                // two situation: either it can reach h, or it reaches h-1,
                //and right child of which is null
                for(int j=ch; j<h; j++)
                    l = l->right;
                // left subtree is full, add #node of left subtree to cnt
                // then start counting right subtree
                if(l){
                    cnt += 1<<(h-ch);
                    p = p->right;
                }
                // left subtree is not complete,
                // start next loop at its left subtree (check if it's complete)
                else p = p->left;
                //current level always increments
                ch++;
            }
            //NOT SURE the exact meaning,
            // but cnt increments when final visited node is the leaf at h level as left child,
            //***while its parent also has the right child***
            // such that, this right child is the only one not counted into cnt, add it after loop?
            //ISN'T THIS THE SCENARIO WHEN BST is a FULLY complete tree?
            if(p) cnt++;
            return (1<<(h-1)) -1 + cnt;
        }
    };
};





#endif /* _22_CountCompleteTreeNodes_h */
