//
//  304_RangeSumQuery2D_Immutable.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/15/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _04_RangeSumQuery2D_Immutable_h
#define _04_RangeSumQuery2D_Immutable_h


class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        sum = matrix;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++)
                sum[i][j] += a(i-1,j) + a(i,j-1) - a(i-1,j-1);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return a(row2, col2) - a(row1-1, col2) - a(row2, col1-1) + a(row1-1, col1-1);
    }
private:
    vector<vector<int>> sum;
    int a(int i, int j){
        return (i>=0 && j>=0) ? sum[i][j]:0;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

#endif /* _04_RangeSumQuery2D_Immutable_h */
