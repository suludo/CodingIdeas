//
//  119_PascalsTriangle.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _19_PascalsTriangle_h
#define _19_PascalsTriangle_h

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1, 0);
        
        for(int i=0; i<=rowIndex; i++){
            for(int j=0; j<i+1; j++){
                if(j==0 || j==i)
                    ret[i-j] = 1;
                else
                    ret[i-j] += ret[i-j-1];
            }
        }
        return ret;
    }
    
    //     [1],
    //    [1,1],
    //   [1,2,1],
    //  [1,3,3,1],
    // [1,4,6,4,1]
};

#endif /* _19_PascalsTriangle_h */
