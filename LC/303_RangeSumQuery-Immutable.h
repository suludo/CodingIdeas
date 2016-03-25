//
//  303_RangeSumQuery-Immutable.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/14/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _03_RangeSumQuery_Immutable_h
#define _03_RangeSumQuery_Immutable_h



class NumArray {
public:
    
    NumArray(vector<int> &nums) {
        sum.assign(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++)
            sum[i] += sum[i-1];
    }
    
    int sumRange(int i, int j) {
        if(i==0)
            return sum[j];
        return sum[j]-sum[i-1];
    }
private:
    vector<int> sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);



#endif /* _03_RangeSumQuery_Immutable_h */
