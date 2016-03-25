//
//  124_BinaryTreeMaximumPathSum.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _24_BinaryTreeMaximumPathSum_h
#define _24_BinaryTreeMaximumPathSum_h


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
    //http://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
    int helper(TreeNode* root, int& m){
        if(!root) return 0;
        int l = helper(root->left, m);
        int r = helper(root->right, m);
        
        int max_single = max(root->val, root->val+max(l,r));
        int max_top = max(max_single, root->val+l+r);
        m = max(max_top, m);
        return max_single;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int m = root->val;
        helper(root, m);
        return m;
    }
};


#endif /* _24_BinaryTreeMaximumPathSum_h */
