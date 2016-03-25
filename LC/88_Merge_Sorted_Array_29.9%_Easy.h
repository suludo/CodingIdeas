/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(n==0) return;
        if(m==0){
            for(int i=0; i<n; i++)
                A[i] = B[i];
            return;
        }
        
        for(int i=m-1; i>=0; i--)
            A[i+n] = A[i];
            
        int sa = n;
        int sb = 0;
        int sm = 0;
        
        while(sm<sa){
            if(sa>=m+n || A[sa]>=B[sb])
                A[sm++]=B[sb++];
            else
                A[sm++]=A[sa++];
        }
    }
};