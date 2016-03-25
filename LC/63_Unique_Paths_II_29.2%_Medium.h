/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty()) return 0;
        int nr = obstacleGrid.size();
        int nc = obstacleGrid[0].size();
        
        if(obstacleGrid[nr-1][nc-1]==1) return 0;
        
        for(int i=nr-1; i>=0; i--){
            for(int j=nc-1; j>=0; j--){
                if(i==(nr-1) && j==(nc-1)) obstacleGrid[i][j] =1;
                else if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = 0;
                }
                else{
                    if(i<(nr-1)) obstacleGrid[i][j] += obstacleGrid[i+1][j];
                    if(j<(nc-1)) obstacleGrid[i][j] += obstacleGrid[i][j+1];
                }
            }
        }
        return obstacleGrid[0][0];
    }
};