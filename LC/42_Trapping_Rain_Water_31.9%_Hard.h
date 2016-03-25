/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/
class Solution {
public:
    int trap(int A[], int n) {
        if(n<=2) return 0;
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        int maxBar = 0;
        for(int i=1; i<n; i++){
            if(A[i]>=A[maxBar])
                maxBar = i;
            l[i] = maxBar;
        }
        maxBar = n-1;
        for(int i=n-2; i>=0; i--){
            if(A[i]>=A[maxBar])
                maxBar = i;
            r[i] = maxBar;
        }
        maxBar = 0;
        for(int i=1; i<n-1; i++){
            maxBar += (min(A[l[i]],A[r[i]])-A[i]);
        }
        return maxBar;
    }
};