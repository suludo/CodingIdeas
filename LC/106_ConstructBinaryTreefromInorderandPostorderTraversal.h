//
//  106_ConstructBinaryTreefromInorderandPostorderTraversal.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _06_ConstructBinaryTreefromInorderandPostorderTraversal_h
#define _06_ConstructBinaryTreefromInorderandPostorderTraversal_h


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
    TreeNode * helper(vector<int> &inorder, vector<int> &postorder, int is, int ps, int len){
        if(len==0) return NULL;
        TreeNode* newNode = new TreeNode(postorder[ps+len-1]);
        if(len==1) return newNode;
        
        int inRootIndex = is;
        for(int i=is; i<is+len; i++){
            if(inorder[i]==postorder[ps+len-1]){
                inRootIndex = i;
                break;
            }
        }
        int subLen = inRootIndex-is;
        TreeNode* l = helper(inorder, postorder, is, ps, subLen);
        TreeNode* r = helper(inorder, postorder, inRootIndex+1, ps+subLen, len-subLen-1);
        newNode->left = l;
        newNode->right = r;
        return newNode;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty() || postorder.empty() || inorder.size()!=postorder.size())
            return NULL;
        TreeNode * ret = helper(inorder, postorder, 0, 0, inorder.size());
        return ret;
    }
};
#endif /* _06_ConstructBinaryTreefromInorderandPostorderTraversal_h */
