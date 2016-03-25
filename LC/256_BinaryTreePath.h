//
//  Header.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef Header_h
#define Header_h



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
    void dfs(TreeNode* root, string path, vector<string> &res){
        if(!root) return;
        
        string s = to_string(root->val);
        path += path.empty() ? "":"->";
        path += s;
        
        if(!root->left && !root->right){
            res.push_back(path);
            return;
        }
        
        dfs(root->left, path, res);
        dfs(root->right, path, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        dfs(root, "", ret);
        return ret;
    }
};


#endif /* Header_h */
