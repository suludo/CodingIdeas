/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        if(n<=0) return ret;
        int x = 0;
        int y = 0;
        int i=0;
        while(i<n*n){
            while(y<n && ret[x][y]==0)
                ret[x][y++] = ++i;
            //printMat(ret);
            y--;
            while(x+1<n && ret[x+1][y]==0)
                ret[++x][y] = ++i;
            //printMat(ret);
            while(y-1>=0 && ret[x][y-1]==0)
                ret[x][--y] = ++i;
            //printMat(ret);
            while(x-1>=0 && ret[x-1][y]==0)
                ret[--x][y] = ++i;
            //printMat(ret);
            y++;
        }
        return ret;
    }
};