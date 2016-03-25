/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

//condition last two if
//consider rectangle when encountering rows/column already met in the last lap

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if(matrix.empty()) return ret;
        int r = matrix.size();
        int c = matrix[0].size();

        int lap = (min(r, c)+1)/2;
        
        for(int l=0; l<lap; l++){
            for(int j=l; j<c-l; j++)
                ret.push_back(matrix[l][j]);
            for(int i=l+1;i<r-l;i++)
                ret.push_back(matrix[i][c-1-l]);
            //if you write this if into the condition into for loop, not gonna work
            //b/c check this out
        //http://stackoverflow.com/questions/18063552/c-multiple-exit-conditions-in-for-loop-multiple-variables-and-ed-or-or-e
            //The comma operator will return the value of the right expression, so writing this:
            if(r-1-l>l) //this if is the trickest part to figure out
                for(int j=c-2-l; j>=l; j--)
                    ret.push_back(matrix[r-1-l][j]);
            if(l<c-1-l) ////this if is the trickest part to figure out
                for(int i=r-2-l; i>l; i--)
                    ret.push_back(matrix[i][l]);
        }
        return ret;
    }
};