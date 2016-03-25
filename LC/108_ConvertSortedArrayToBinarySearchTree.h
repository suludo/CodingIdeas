//
//  108_ConvertSortedArrayToBinarySearchTree.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _08_ConvertSortedArrayToBinarySearchTree_h
#define _08_ConvertSortedArrayToBinarySearchTree_h


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
    TreeNode* helper(vector<int> &v, int start, int end){
        if(start > end) return NULL;
        if(start == end) return (new TreeNode(v[start]));
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = helper(v, start, mid-1);
        root->right = helper(v, mid+1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return helper(num, 0, num.size()-1);
    }
};

#endif /* _08_ConvertSortedArrayToBinarySearchTree_h */
