//
//  200_NumberOfIslands.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _00_NumberOfIslands_h
#define _00_NumberOfIslands_h


//NOT ONLY DETECT NUMBER OF ISLANDS
//ALSO RETURN THE LARGEST AREA
class Solution {
public:
    int mark(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') return 0;
        grid[i][j] = '0';
        return 1+ mark(i+1, j, grid)+mark(i, j+1, grid)+mark(i-1, j, grid)+mark(i, j-1, grid);
    }
    void print(vector< vector<char> > & grid){
        if(grid.empty()) return;
        int r = grid.size();
        int c = grid[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    int numIslands(vector<vector<char>>& grid) {
        print(grid);
        int ret = 0;
        int area = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++)
                if(grid[i][j]=='1'){
                    ++ret;
                    area = max(area, mark(i,j,grid));
                }
        }
        cout<<"num: "<<ret<<" area max: "<<area;
        return ret;
    }
};

#endif /* _00_NumberOfIslands_h */
