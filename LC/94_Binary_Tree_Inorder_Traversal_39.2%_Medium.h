/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> stk;
        vector<int> ret;
        TreeNode* cur = root;
        while(!stk.empty() || cur){
            if(cur){
                stk.push(cur);
                cur = cur->left;
            }
            else{
                ret.push_back(stk.top()->val);
                cur = stk.top()->right;
                stk.pop();
            }
        }
        return ret;
    }
};