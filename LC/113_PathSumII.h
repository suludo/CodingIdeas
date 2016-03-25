//
//  113_PathSumII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _13_PathSumII_h
#define _13_PathSumII_h


//pay attn to how the path is popped out

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    void helper(TreeNode* root, int sum, int curSum, vector<int> &path, vector<vector<int>>& res){
        if(!root) return;
        curSum += root->val;
        path.push_back(root->val);
        if(!root->left && !root->right){
            if(curSum == sum){
                res.push_back(path);
                path.pop_back();
                return;
            }
        }
        helper(root->left, sum, curSum, path, res);
        helper(root->right, sum, curSum, path, res);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> ret;
        helper(root, sum, 0, path, ret);
        return ret;
    }
};


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};
#endif /* _13_PathSumII_h */
