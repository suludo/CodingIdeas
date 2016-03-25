//
//  300_LongestIncreasingSubsequence.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/15/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _00_LongestIncreasingSubsequence_h
#define _00_LongestIncreasingSubsequence_h

#include <vector>
using namespace std;
//DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        //max length increasing seq of the array[0...i] including nums[i]
        vector<int> dp(nums.size(), 1);
        int ret = 0;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++)
                if(nums[j]<nums[i])
                    dp[i] = max(dp[i],dp[j]+1);
            ret = max(dp[i], ret);
        }
        return ret;
    }
};

//Binary Search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            auto it = std::lower_bound(v.begin(), v.end(), nums[i]);
            //nums[i] is LARGER than all the element in v[]
            if(it == v.end())
                v.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return v.size();
    }
};

/*

//geeksforgeeks solution
//http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

From the observations, we need to maintain lists of increasing sequences.

In general, we have set of active lists of varying length. We are adding an element A[i] to these lists. We scan the lists (for end elements) in decreasing order of their length. We will verify the end elements of all the lists to find a list whose end element is smaller than A[i] (floor value).

Our strategy determined by the following conditions,

1. If A[i] is smallest among all end candidates of active lists, we will start new active list of length 1.

2. If A[i] is largest among all end candidates of active lists, we will clone the largest active list, and extend it by A[i].

3. If A[i] is in between, we will find a list with largest end element that is smaller than A[i]. Clone and extend this list by A[i]. We will discard all other lists of same length as that of this modified list.

Note that at any instance during our construction of active lists, the following condition is maintained.

“end element of smaller list is smaller than end elements of larger lists”.

 It will be clear with an example, let us take example from wiki {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}.
 
 A[0] = 0. Case 1. There are no active lists, create one.
 0.
 -----------------------------------------------------------------------------
 A[1] = 8. Case 2. Clone and extend.
 0.
 0, 8.
 -----------------------------------------------------------------------------
 A[2] = 4. Case 3. Clone, extend and discard.
 0.
 0, 4.
 0, 8. Discarded
 -----------------------------------------------------------------------------
 A[3] = 12. Case 2. Clone and extend.
 0.
 0, 4.
 0, 4, 12.
 -----------------------------------------------------------------------------
 A[4] = 2. Case 3. Clone, extend and discard.
 0.
 0, 2.
 0, 4. Discarded.
 0, 4, 12.
 -----------------------------------------------------------------------------
 A[5] = 10. Case 3. Clone, extend and discard.
 0.
 0, 2.
 0, 2, 10.
 0, 4, 12. Discarded.
 -----------------------------------------------------------------------------
 A[6] = 6. Case 3. Clone, extend and discard.
 0.
 0, 2.
 0, 2, 6.
 0, 2, 10. Discarded.
 -----------------------------------------------------------------------------
 A[7] = 14. Case 2. Clone and extend.
 0.
 0, 2.
 0, 2, 6.
 0, 2, 6, 14.
 -----------------------------------------------------------------------------
 A[8] = 1. Case 3. Clone, extend and discard.
 0.
 0, 1.
 0, 2. Discarded.
 0, 2, 6.
 0, 2, 6, 14.
 -----------------------------------------------------------------------------
 A[9] = 9. Case 3. Clone, extend and discard.
 0.
 0, 1.
 0, 2, 6.
 0, 2, 6, 9.
 0, 2, 6, 14. Discarded.
 -----------------------------------------------------------------------------
 A[10] = 5. Case 3. Clone, extend and discard.
 0.
 0, 1.
 0, 1, 5.
 0, 2, 6. Discarded.
 0, 2, 6, 9.
 -----------------------------------------------------------------------------
 A[11] = 13. Case 2. Clone and extend.
 0.
 0, 1.
 0, 1, 5.
 0, 2, 6, 9.
 0, 2, 6, 9, 13.
 -----------------------------------------------------------------------------
 A[12] = 3. Case 3. Clone, extend and discard.
 0.
 0, 1.
 0, 1, 3.
 0, 1, 5. Discarded.
 0, 2, 6, 9.
 0, 2, 6, 9, 13.
 -----------------------------------------------------------------------------
 A[13] = 11. Case 3. Clone, extend and discard.
 0.
 0, 1.
 0, 1, 3.
 0, 2, 6, 9.
 0, 2, 6, 9, 11.
 0, 2, 6, 9, 13. Discarded.
 -----------------------------------------------------------------------------
 A[14] = 7. Case 3. Clone, extend and discard.
 0.
 0, 1.
 0, 1, 3.
 0, 1, 3, 7.
 0, 2, 6, 9. Discarded.
 0, 2, 6, 9, 11.
 ----------------------------------------------------------------------------
 A[15] = 15. Case 2. Clone and extend.
 0.
 0, 1.
 0, 1, 3.
 0, 1, 3, 7.
 0, 2, 6, 9, 11.
 0, 2, 6, 9, 11, 15. <-- LIS List
 ----------------------------------------------------------------------------

 
*/

#endif /* _00_LongestIncreasingSubsequence_h */


//generate actual sequence list


/*
 #include <iostream>
 #include <string.h>
 #include <stdio.h>
 using namespace std;
 
 // Binary search
 int GetCeilIndex(int A[], int T[], int l, int r, int key) {
 int m;
 
 while( r - l > 1 ) {
 m = l + (r - l)/2;
 if( A[T[m]] >= key )
 r = m;
 else
 l = m;
 }
 
 return r;
 }
 
 int LongestIncreasingSubsequence(int A[], int size) {
 // Add boundary case, when array size is zero
 // Depend on smart pointers
 
 int *tailIndices = new int[size];
 int *prevIndices = new int[size];
 int len;
 
 memset(tailIndices, 0, sizeof(tailIndices[0])*size);
 memset(prevIndices, 0xFF, sizeof(prevIndices[0])*size);
 
 tailIndices[0] = 0;
 prevIndices[0] = -1;
 len = 1; // it will always point to empty location
 for( int i = 1; i < size; i++ ) {
 if( A[i] < A[tailIndices[0]] ) {
 // new smallest value
 tailIndices[0] = i;
 } else if( A[i] > A[tailIndices[len-1]] ) {
 // A[i] wants to extend largest subsequence
 prevIndices[i] = tailIndices[len-1];
 tailIndices[len++] = i;
 } else {
 // A[i] wants to be a potential condidate of future subsequence
 // It will replace ceil value in tailIndices
 int pos = GetCeilIndex(A, tailIndices, -1, len-1, A[i]);
 
 prevIndices[i] = tailIndices[pos-1];
 tailIndices[pos] = i;
 }
 }
 cout << "LIS of given input" << endl;
 for( int i = tailIndices[len-1]; i >= 0; i = prevIndices[i] )
 cout << A[i] << "   ";
 cout << endl;
 
 delete[] tailIndices;
 delete[] prevIndices;
 
 return len;
 }
 
 int main() {
 int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
 int size = sizeof(A)/sizeof(A[0]);
 
 printf("LIS size %d\n", LongestIncreasingSubsequence(A, size));
 
 return 0;
 }
 
 */

