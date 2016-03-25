/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
class Solution {
    
public:

	// O(LogM+LogN)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        if(target<matrix[0][0] || target>matrix[m-1][n-1]) return false;
        
        int l = 0, r = m-1;
        
        while(l<r){
            int mid = l + (r-l)/2;
            if(matrix[mid][n-1]<target) l=mid+1;
            else r = mid;
        }
        if(matrix[l][n-1] == target) return true;
        int row = l;
        l=0, r = n-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(matrix[row][mid]==target) return true;
            if(matrix[row][mid]<target) l = mid+1;
            else r = mid-1;
        }
        return target==matrix[row][l];
		
		//O(Log(M+N))
        // int l=0, r = m*n-1;
        // while(l<r){
        //     int mid = l + (r-l)/2;
        //     int i = mid/n;
        //     int j = mid%n;
        //     if(matrix[i][j]==target) return true;
        //     if(matrix[i][j]<target) l=mid+1;
        //     else r = mid-1;
        // }
        //return target==matrix[l/n][l%n];
    }
};