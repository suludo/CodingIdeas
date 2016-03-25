/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    //find the "k"th element between the two arrays
    double helper(vector<int>& nums1, vector<int>& nums2, int s1, int s2, int k){
        
        if(nums1.size()>nums2.size())
            return helper(nums2, nums1, s2, s1, k);
        // smaller array has run out of range
        if(s1>=nums1.size())
            return nums2[s2+k-1];
        
        if(k==1)
            if(s1<nums1.size() && s2<nums2.size()) 
                return min(nums1[s1], nums2[s2]);
            else
                return s1<nums1.size() ? nums1[s1]:nums2[s2];
                
        int ofs1 = min(k/2, (int)nums1.size()-s1);
        int ofs2 = k-ofs1;
        
        if(nums1[s1+ofs1-1]==nums2[s2+ofs2-1])
            return nums1[s1+ofs1-1];
        else if(nums1[s1+ofs1-1]<nums2[s2+ofs2-1])
            return helper(nums1, nums2, s1+ofs1, s2, k-ofs1);
        return helper(nums1, nums2, s1, s2+ofs2, k-ofs2);
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int lsum = n1+n2;

        if(nums1.empty() && nums2.empty())
                return INT_MIN;

        bool odd = lsum%2;
        //cout<<(1+lsum/2)<<" "<<helper(nums1, nums2, 0, 0, 1+lsum/2)<<endl;
        //cout<<(lsum/2)<<" "<<helper(nums1, nums2, 0, 0, lsum/2)<<endl;
        if(odd)
            return helper(nums1, nums2, 0, 0, 1+lsum/2);
        else
            return 0.5*(helper(nums1,nums2,0,0,lsum/2) + helper(nums1,nums2,0,0,1+lsum/2));
    }
};

class Solution {
public:

    double findKthNumber(int A[], int m, int B[], int n, int k){
        if (m>n) return findKthNumber(B, n, A, m, k);
        if(m==0) return B[k-1];
        if(k==1) return min(A[0], B[0]);
        int pa = min(k/2, m);
        int pb = k-pa;
        if(A[pa-1]==B[pb-1]) return A[pa-1];
        if(A[pa-1]<B[pb-1]) return findKthNumber(A+pa, m-pa, B, n, k-pa);
        return findKthNumber(A, m, B+pb, n-pb, k-pb);
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m+n;
        if(total%2)
            return findKthNumber(A, m, B, n, total/2+1);
        else
            return (findKthNumber(A,m,B,n,total/2)+findKthNumber(A,m,B,n,total/2+1))/2;
    }
};