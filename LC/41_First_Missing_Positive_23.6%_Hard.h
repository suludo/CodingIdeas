/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i=0; i<n; i++){
            if(A[i]>0 && A[i]<=n)
			//put A[i], if not equal to the correct val (i+1), to the right place A[ A[i]-1 ]
                if(A[i]!=(i+1) && A[A[i]-1]!=A[i]){
                    //this way is wrong! because A[i] has been changed when A[A[i]-1]=tmp
                    //int tmp = A[i];
                    //A[i] = A[A[i]-1];
                    //A[A[i]-1] = tmp;
					int temp = A[A[i]-1];
                    A[A[i]-1] = A[i];
                    A[i] = temp;
                    //this is included in <algorithm>
                    //swap(A[i], A[A[i]-1]);
                    i--;
                }
        }
        for(int i=0; i<n; i++)
            if(A[i]!=(i+1))
                return i+1;
        return n+1;
    }
};