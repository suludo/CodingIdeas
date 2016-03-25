//
//  307_RangeSumQuery-Mutable.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/14/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _07_RangeSumQuery_Mutable_h
#define _07_RangeSumQuery_Mutable_h

#include <vector>

using namespace std;
/*
//NOTE BY RAYMON
//BIT[0...N]
//ARR[0...N-1]
 BIT[i] include M(i) array sums from arr[i-M(i)+1] to arr[i],
 likewise, BIT[i-M(i)] contains M(i-M(i)) sums
 M(i) is the operator 2^(last set digit (digit set to 1) in i)
 if update ARR[i], first update BIT[i] (self includes ARR[i])
 How to find the indices > i that contains #elements > (indices-i) ?
 like, i|....j...indices|
        |  M(indices)   |
 => 2^(index to last set digit) = M(indices) > (indices-i)
 assume indices = 0x[ ABC..XYZ100..00 ], where last set digit is r
 contains ARR sum from ABC..XYZ000..01 to ABC..XYZ100..00, # = 2^r
 whereas i is in the form of abc..xyz0***
 
 
 such that BIT[indices] is updated whenever ARR from ABC..XYZ0001 to ABC..XYZ1000 get updated
 generally BIT[ABC..XYZ100..00] gets updated when ARR[ABC..XYZ000..01] ~ ARR[ABC..XYZ100..00] are muted.
 
                                                                BIT
 ARR
 ABC..XYZ000..01  ABC..XYZ000..10   ...   ABC..XYZ011..11  ABC..XYZ100..00
 
 ABC..XYZ100..00
 
 ABC..XYZ010..00
 ABC..XYZ011..00
 ...
 ABC..XYZ011..10
 ABC..XYZ011..11
 
 
 cannot figure out UNTIL saw graph in 
 https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
TO BE REVIEWED:
                                      *r*
 logic is this: consider i is abc...xyz100...00
                                       ( n 0's )
 the n lower zeros bits right to the set bit 1, all the rumber starting abc...xyz100...01 to abc...xyz111...11 cannot cover i=abc...xyz100...00, up until (abc...xyz111...11 + 1), where the higher iterative set bit 1 contains definitely more than 2^r number of elements downward, where *r* is the index of lowest set bit of i. Find the next BIT element to be updated is similar following this procedure, i.e. add the last set bit in i, which is i + ( i & -i )
 
 */

//The idea is based on the fact that all positive integers can be represented as sum of powers of 2. For example 19 can be represented as 16 + 2 + 1. Every node of BI Tree stores sum of n elements where n is a power of 2. For example, in the above first diagram for getSum(), sum of first 12 elements can be obtained by sum of last 4 elements (from 9 to 12) plus sum of 8 elements (from 1 to 8). The number of set bits in binary representation of a number n is O(Logn). Therefore, we traverse at-most O(Logn) nodes in both getSum() and update() operations. Time complexity of construction is O(nLogn) as it calls update() for all n elements.
class NumArray {
    //TWO APPROACHES
    //https://leetcode.com/discuss/70202/17-ms-java-solution-with-segment-tree
    //SOLUTION BASED ON THIS ONE
    //http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
    vector<int> BIT; //Binary Index Tree
    vector<int> elem;
    void updateBIT(int i, int val){ // 1<=i<=N
        int N = BIT.size()-1;
        //find all the index nodes larger than i, whereas also use i for the range sum that the node covers
        while(i<=N){
            BIT[i] += val;
            i += i&(-i);
        }
        //cout<<"updating..."<<i<<endl;
    }
    int getSum(int i){ // 1<=i<=N
        int sum = 0;
        while(i>0){
            sum += BIT[i];
            //Parent can be obtained by removing the last set bit from index, i.e., index = index - (index & (-index))
            //i.e. subtract the current 2^k range number, k is the lowest 1 bit.
            i -= i&(-i);
        }
        //cout<<"getSum = "<<sum<<endl;
        return sum;
    }
public:
    NumArray(vector<int> &nums) {
        int N = nums.size();
        //range sum of the first N elements
        BIT.assign(N+1, 0);
        for(int i=0; i<N; i++){
            //cout<<"init.. update BIT node "<<(i+1)<<endl;
            updateBIT(i+1, nums[i]);
        }
        elem = nums;
    }
    
    void update(int i, int val) {
        if(i<0 || i>=(BIT.size()-1)) return;
        //updateBIT(i+1, val-BIT[i+1]);
        //The update process needs to make sure that all BITree nodes that have arr[i] as part of the section they cover must be updated. We get all such nodes of BITree by repeatedly adding the decimal number corresponding to the last set bit.
        updateBIT(i+1, val-elem[i]);
        elem[i] = val;
    }
    
    int sumRange(int i, int j) {
        return getSum(j+1)-getSum(i);
    }
};

void test(){}
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
#endif /* _07_RangeSumQuery_Mutable_h */
