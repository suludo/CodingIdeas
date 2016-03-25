/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
public:
//https://leetcode.com/discuss/15997/any-shortest-o-1-space-solution

//practise on my own
    void setZeroes(vector<vector<int> > &matrix) {
        bool col0 = false;
        int r = matrix.size();
        int c = matrix[0].size();
        
        for(int i=0; i<r; i++){
            if(matrix[i][0]==0) col0 = true;
            for(int j=1; j<c; j++){
                if(matrix[i][j]==0)
                    matrix[i][0] = matrix[0][j] = 0; //matrix[0][j] already set the row 0
            }
        }
        //reverse order intends to change the row0 at last
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=1; j--){// lower bound must be 1 instead of 0
                                      // otherwise it tends to use matrix[0][j] where j==0, to set 0 for all values of 0 column, 
                                      // E.G. first row value is    1 0 1 1 1 , matrix[0][0] was set to 0, so everytime at column 0
                                      //it will use this set 0 value to set all column 0 value to 0, while it's not necessarily true
                                      // while the 0th column set-zero only controlled by col0
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j] = 0;
            }
            if(col0) matrix[i][0] = 0;
        }
        
    }
};