//
//  231_PowerOfTwo.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _31_PowerOfTwo_h
#define _31_PowerOfTwo_h


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        
        return (n &(n-1)) == 0;
    }
};


#endif /* _31_PowerOfTwo_h */
