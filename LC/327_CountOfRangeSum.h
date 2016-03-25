//
//  327_CountOfRangeSum.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _27_CountOfRangeSum_h
#define _27_CountOfRangeSum_h

class Solution {
private:
    //https://leetcode.com/discuss/79083/share-my-solution
    // merge sort [start, end]
    int helper(vector<long>& sums, int start, int end, int lower, int upper){
        if(end-start<1) return 0; //this has to be calculated by A PAIR of prefix sums
        int mid = start+(end-start)/2;
        int count = helper(sums, start, mid, lower, upper) + helper(sums, mid+1, end, lower, upper);
        vector<long> cache(end-start+1);
        int j=mid+1, k=mid+1, t=mid+1;
        //find in the second merged vector, while merge the two into one big list
        for(int i=start, r=0; i<=mid; i++){
            //multiple pointers, pay attn, k, j, t are monotonically increasing
            while(k<=end && sums[k]-sums[i]<lower) k++;
            while(j<=end && sums[j]-sums[i]<=upper) j++;
            //merge at every i
            while(t<=end && sums[t]<=sums[i]) cache[r++] = sums[t++];
            cache[r++] = sums[i];
            count += (j-k);
        }
        //WHY t-start instead of end-start?
        //bcz t does not necessarily reach end,
        //e.g. what if above i running out of mid
        //while t is still hanging in the middle with larger value than sums[i-1]?
        //this case, values in cache[t,end-1] are ALL 0's!!
        //such that, just alter the [start,t-1] in sums, leave [t,end-1] array as is already sorted
        for(int i=0; i<t-start; i++)
            sums[start+i] = cache[i];
        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.empty()) return 0;
        int N = nums.size();
        vector<long> sums(N+1,0); //sums might overflow, use higher bits
        for(int i=1; i<=N; i++) sums[i] = sums[i-1]+nums[i-1];
        return helper(sums, 0, N, lower, upper);
    }
};


#endif /* _27_CountOfRangeSum_h */
