//
//  Verify Preorder Serialization of a Binary Tree.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef Verify_Preorder_Serialization_of_a_Binary_Tree_h
#define Verify_Preorder_Serialization_of_a_Binary_Tree_h


class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return true;
        int cur = 1;
        int next = 0;
        
        stringstream ss(preorder);
        string s;
        while(getline(ss, s, ',')){
            if(cur==0) return false;
            
            if(s!="#") next+=2;
            cur--;
            if(cur==0){
                cur = next;
                next = 0;
            }
        }
        return cur==0;
    }
};

#endif /* Verify_Preorder_Serialization_of_a_Binary_Tree_h */
