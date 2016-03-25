//
//  Longest Increasing Path in a Matrix.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef Longest_Increasing_Path_in_a_Matrix_h
#define Longest_Increasing_Path_in_a_Matrix_h


class Solution {
    vector<vector<int>> mp; // maximum length at (x,y)
public:
    
    int dfs(int x, int y, int r, int c, vector<vector<int>>&matrix){
        if(mp[x][y]) return mp[x][y];
        
        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        for(auto a : dirs){
            int xx = x+a.first;
            int yy = y+a.second;
            if(xx>=r || yy>=c || xx<0 || yy<0 || matrix[xx][yy]<=matrix[x][y]) continue;
            mp[x][y] = max(mp[x][y], dfs(xx,yy, r, c, matrix));
        }
        return ++mp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        if (matrix.empty()) return ret;
        int r = matrix.size(), c = matrix[0].size();
        mp.assign(r, vector<int>(c));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ret = max(ret, dfs(i,j,r, c, matrix));
            }
        }
        return ret;
    }
};

#endif /* Longest_Increasing_Path_in_a_Matrix_h */
