/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

class Solution {
public:
    int helper(vector<int> h){
        if(h.empty()) return 0;
        stack<int> ascend;
        int maxArea=0;
        h.push_back(0);
        for(int i=0; i<h.size(); i++){
            if(ascend.empty() || h[i]>=h[ascend.top()]) 
                ascend.push(i);
            else{
                int t = ascend.top();
                ascend.pop();
                maxArea = max(maxArea, ascend.empty() ? i*h[t] : (i-ascend.top()-1)*h[t]);
                i--;
            }
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        vector<int> h(matrix[0].size(), 0);
        int maxArea = 0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++)
                h[j]=(matrix[i][j]=='1' ? h[j]+1:0);
            maxArea = max(maxArea, helper(h));
        }
        return maxArea;
    }
};