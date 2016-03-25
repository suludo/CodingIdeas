//
//  258_AddDigits.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _58_AddDigits_h
#define _58_AddDigits_h


class Solution {
public:
    int addDigits(int num) {
        return 1+(num-1)%9;
    }
};

#endif /* _58_AddDigits_h */
