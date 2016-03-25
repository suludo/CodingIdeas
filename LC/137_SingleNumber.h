//
//  137_SingleNumber.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _37_SingleNumber_h
#define _37_SingleNumber_h


class Solution {
public:
    // int singleNumber(vector<int>& A) {
    //     int n = A.size();
    //     int ones = 0;
    //     int twos = 0;
    //     int threes = 0;
    //     int ret = 0;
    //     for(int i=0; i<n; i++){
    //         //threes = twos & A[i];
    //         twos |= ones&A[i];
    //         //0     0    no matter what, twos will be 0
    //         //0     1    twos will be set to 1 if A[i] is 1, makes two occurrences of "1"
    //         //1     0    A[i] on "0" ,twos remains 1;
    //                   //A[i] on "1", makes threes on "1", twos reset in the following step
    //         //1     1    couldn't be both 1
    //         ones = ones^A[i];
    //         threes = (twos & ones);
    //         twos &= ~threes;
    //         ones &= ~threes;
    //     }
    //     return ones;
    // }
    
    //calculate threes first for better understanding
    // then after calculating twos and ones, conveniently reset the bits reaching 3 multipliers.
    int singleNumber(vector<int>& A) {
        int n = A.size();
        int ones=0, twos=0, threes=0;
        for(int i=0; i<n; i++){
            threes = twos & A[i];
            
            twos |= ones&A[i];
            twos &= ~threes;
            
            ones ^= A[i];
            ones &= ~threes;
            
        }
        return ones;
    }
};


#endif /* _37_SingleNumber_h */
