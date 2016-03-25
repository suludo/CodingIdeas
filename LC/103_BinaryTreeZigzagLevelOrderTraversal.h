//
//  103_BinaryTreeZigzagLevelOrderTraversal.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _03_BinaryTreeZigzagLevelOrderTraversal_h
#define _03_BinaryTreeZigzagLevelOrderTraversal_h


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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        vector<TreeNode*> nodesPerLevel;
        nodesPerLevel.push_back(root);
        vector<TreeNode*> nodesNextLevel;
        bool ltor = true;
        while(!nodesPerLevel.empty()){
            vector<int> valsPerLevel;
            for(int i=0; i<nodesPerLevel.size(); i++){
                if(nodesPerLevel[i]->left) nodesNextLevel.push_back(nodesPerLevel[i]->left);
                if(nodesPerLevel[i]->right) nodesNextLevel.push_back(nodesPerLevel[i]->right);
            }
            for(int i=0; i<nodesPerLevel.size(); i++){
                if(ltor) valsPerLevel.push_back(nodesPerLevel[i]->val);
                else valsPerLevel.push_back(nodesPerLevel[nodesPerLevel.size()-1-i]->val);
            }
            ret.push_back(valsPerLevel);
            nodesPerLevel = nodesNextLevel;
            nodesNextLevel.clear();
            ltor = !ltor;
        }
        return ret;
    }
};
#endif /* _03_BinaryTreeZigzagLevelOrderTraversal_h */
