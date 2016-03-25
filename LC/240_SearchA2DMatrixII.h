//
//  240_SearchA2DMatrixII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _40_SearchA2DMatrixII_h
#define _40_SearchA2DMatrixII_h

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size()-1;
        int j = 0;
        
        while(i>=0 && j<matrix[0].size()){
            
            if(matrix[i][j] == target)
                return true;
            
            if(matrix[i][j] > target)
                i--;
            else
                j++;
        }
        return false;
    }
};


#endif /* _40_SearchA2DMatrixII_h */
