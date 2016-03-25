/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if(matrix.empty()) return;
        for(int i=0; i<matrix.size(); i++){
            for(int j=i+1; j<matrix[0].size(); j++){
                //int tmp = matrix[i][j];
                //matrix[i][j] = matrix[j][i];
                //matrix[j][i] = tmp;
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<matrix.size(); i++){
            int l = 0;
            int r = matrix[i].size()-1;
            while(l<r){
                //int tmp = matrix[i][l];
                //matrix[i][l] = matrix[i][r];
                //matrix[i][r] = tmp;
                swap(matrix[i][l],matrix[i][r]);
                l++;
                r--;
            }
        }
    }
};