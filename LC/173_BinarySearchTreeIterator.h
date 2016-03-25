//
//  173_BinarySearchTreeIterator.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _73_BinarySearchTreeIterator_h
#define _73_BinarySearchTreeIterator_h



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* start;
    stack<TreeNode*> st;
    BSTIterator(TreeNode *root) {
        start = root;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return(st.empty()==false || start!=NULL);
    }
    
    /** @return the next smallest number */
    int next() {
        while(start){
            st.push(start);
            start = start->left;
        }
        
        TreeNode* node = st.top();
        st.pop();
        // if the node doesn't have right child
        // then in the next time next() is called,
        // while won't be called, instead it directly uses top elem
        // of the stack as the next elem
        // start IS ALLOWED TO BE NULL!
        start = node->right;
        return node->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


#endif /* _73_BinarySearchTreeIterator_h */
