//
//  326_PowerOfThree.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _26_PowerOfThree_h
#define _26_PowerOfThree_h


class Solution {
public:
    int maxIntThreeExp(){
        int64_t ret = 1;
        while(ret*3<=INT_MAX)
            ret *= 3;
        return ret;
    }
    bool isPowerOfThree(int n) {
        return n > 0 && (maxIntThreeExp() % n == 0);
    }
};

#endif /* _26_PowerOfThree_h */
