//
//  130_SurroundedRegions.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _30_SurroundedRegions_h
#define _30_SurroundedRegions_h


class Solution {
public:
    int index(int r, int c, vector<vector<char>> &board){
        return r*board[0].size()+c;
    }
    void solve(vector<vector<char>> &board) {
        
        if(board.size()==0) return;
        
        queue<int> q;
        int nRow = board.size();
        int nCol = board[0].size();
        
        for(int j=0; j<nCol; j++){
            if(board[0][j]=='O'){
                board[0][j]='U';
                q.push(index(0,j,board));
            }
            if(board[nRow-1][j]=='O'){
                board[nRow-1][j] = 'U';
                q.push(index(nRow-1,j,board));
            }
        }
        
        for(int i=1; i<nRow-1; i++){
            if(board[i][0]=='O'){
                board[i][0]='U';
                q.push(index(i,0,board));
            }
            if(board[i][nCol-1]=='O'){
                board[i][nCol-1]='U';
                q.push(index(i,nCol-1,board));
            }
        }
        
        while(!q.empty()){
            
            int r = q.front()/board[0].size();
            int c = q.front()%board[0].size();
            
            q.pop();
            
            if(r+1<nRow-1 && board[r+1][c]=='O'){
                board[r+1][c]='U';
                q.push(index(r+1,c,board));
            }
            if(r-1>0 && board[r-1][c]=='O'){
                board[r-1][c]='U';
                q.push(index(r-1,c,board));
            }
            if(c+1<nCol-1 && board[r][c+1]=='O'){
                board[r][c+1]='U';
                q.push(index(r,c+1,board));
            }
            if(c-1>0 && board[r][c-1]=='O'){
                board[r][c-1]='U';
                q.push(index(r,c-1,board));
            }
        }
        
        for(int i=0; i<nRow; i++)
            for(int j=0; j<nCol; j++)
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='U')
                    board[i][j] ='O';
    }
};

#endif /* _30_SurroundedRegions_h */
