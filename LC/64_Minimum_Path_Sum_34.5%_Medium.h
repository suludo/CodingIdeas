/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return INT_MAX;
        int r = grid.size();
        int c = grid[0].size();
        
        vector<int> v(c, 0);
        for(int i=c-1; i>=0; i--){
            if(i==(c-1))
                v[i] = grid[r-1][i];
            else
                v[i] = grid[r-1][i]+v[i+1];
        }
        
        for(int i=r-2; i>=0; i--){
            for(int j=c-1; j>=0; j--){
                if(j==(c-1))
                    v[j] = grid[i][j]+v[j];
                else
                    v[j] = grid[i][j]+min(v[j+1], v[j]);
            }
        }
        
        return v[0];
    }
};