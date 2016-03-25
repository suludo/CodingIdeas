/*Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.*/


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
    void inorder(TreeNode* root){
        
        if(!root) return;
        
        inorder(root->left);
        
        if(prev && prev->val > root->val){
            if(!first)
                first = prev;
            second = root;
        }
        
        prev = root;
        
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = first = second = NULL;
        inorder(root);
        if(first && second)
            swap(first->val, second->val);
    }
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
};