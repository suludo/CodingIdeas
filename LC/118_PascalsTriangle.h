//
//  118_PascalsTriangle.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _18_PascalsTriangle_h
#define _18_PascalsTriangle_h


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ret;
        
        for(int i=1; i<=numRows; i++){
            vector<int> perRow;
            for(int j=0; j<i; j++){
                if(j==0 || j==(i-1)) perRow.push_back(1);
                else{
                    perRow.push_back(ret[i-2][j-1]+ret[i-2][j]);
                }
            }
            ret.push_back(perRow);
        }
        return ret;
    }
};

#endif /* _18_PascalsTriangle_h */
