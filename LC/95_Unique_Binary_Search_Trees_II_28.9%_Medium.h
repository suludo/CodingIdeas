/*

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/

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
     vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> ret;
        if(start>end){
            //THIS LINE IS IMPORTANT
            ret.push_back(NULL);
            return ret;
        }
        for(int i=start; i<=end; i++){
            
            vector<TreeNode*> l = helper(start, i-1);
            vector<TreeNode*> r = helper(i+1, end);
            
            for(int j=0; j<l.size(); j++){
                for(int k=0; k<r.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = l[j];
                    root->right = r[k];
                    ret.push_back(root);
                }
            }
            
        }
        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n>0) res = helper(1, n);
        return res;
    }
};