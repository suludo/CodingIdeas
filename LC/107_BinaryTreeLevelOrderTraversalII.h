//
//  107_BinaryTreeLevelOrderTraversalII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _07_BinaryTreeLevelOrderTraversalII_h
#define _07_BinaryTreeLevelOrderTraversalII_h

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        vector<TreeNode*> curLayer;
        curLayer.push_back(root);
        vector<TreeNode*> nextLayer;
        while(!curLayer.empty()){
            vector<int> v;
            nextLayer.clear();
            for(int i=0; i<curLayer.size(); i++){
                v.push_back(curLayer[i]->val);
                if(curLayer[i]->left) nextLayer.push_back(curLayer[i]->left);
                if(curLayer[i]->right) nextLayer.push_back(curLayer[i]->right);
            }
            ret.insert(ret.begin(), v);
            //curLayer.clear();
            curLayer = nextLayer;
        }
        return ret;
    }
};

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
    void dfs(TreeNode* root, int h, vector<vector<int>>& res){
        if(!root) return;
        if(h==res.size()) res.push_back(vector<int>());
        res[h].push_back(root->val);
        dfs(root->left, h+1, res);
        dfs(root->right, h+1, res);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        dfs(root, 0, ret);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


#endif /* _07_BinaryTreeLevelOrderTraversalII_h */
