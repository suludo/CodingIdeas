//
//  289_GameOfLife.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/17/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _89_GameOfLife_h
#define _89_GameOfLife_h


class Solution {
public:
    //two gists:
    //1. use the second bit in the int element to store the next state
    //2. trick in the counting of neighbors
    void gameOfLife(vector<vector<int>>& board) {
        
        int r = board.size();
        int c = board[0].size();
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int count = 0;
                
                for(int ii=max(i-1, 0); ii<min(i+2, r); ii++){
                    for(int jj=max(j-1,0); jj<min(j+2, c); jj++){
                        count += board[ii][jj] & 1;
                    }
                }
                if((count==3&&board[i][j]==1) || (count==3&&board[i][j]==0) || (count==4&&board[i][j]==1))
                    //if(count==3 || count-board[i][j]==3)
                    board[i][j] |= 2;
            }
        }
        
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                board[i][j] >>= 1;
        
    }
};

#endif /* _89_GameOfLife_h */
