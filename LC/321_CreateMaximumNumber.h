//
//  321_CreateMaximumNumber.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _21_CreateMaximumNumber_h
#define _21_CreateMaximumNumber_h

class Solution {
public:
    //TO BE REVIEWED
    //http://algobox.org/create-maximum-number/
    //https://leetcode.com/discuss/75804/short-python-ruby-c
    
    vector<int> maxArray(vector<int> &input, int len){
        int64_t N = input.size();
        vector<int> ret;
        if(len<=0 || N==0 || N<len) return ret;
        ret.assign(len,0);
        int j = 0; //length of the current ret array
        for(int i=0; i<N; i++){
            //int rem = N-i;
            while(j+(N-i)>len && j>0 && input[i]>ret[j-1]) j--;
            if(j<len) ret[j++] = input[i];
        }
        return ret;
    }
    bool gt(vector<int>&nums1, vector<int>&nums2, int i, int j){
        while(i<nums1.size() && j<nums2.size() && nums1[i]==nums2[j]){
            i++;
            j++;
        }
        return (j==nums2.size() || (i<nums1.size() && nums1[i]>nums2[j]));
    }
    vector<int> merge(vector<int>nums1, vector<int> nums2){
        int i=0, j=0, sz=0;
        int64_t len = nums1.size()+nums2.size();
        vector<int> ret(len);
        while(sz<len)
            ret[sz++] = (gt(nums1, nums2, i, j) ? nums1[i++]:nums2[j++]);
        return ret;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.size()>nums2.size()) return maxNumber(nums2, nums1, k);
        vector<int> ret;
        if(k>(nums1.size()+nums2.size())) return ret;
        ret.assign(k,0);
        int m = nums1.size();
        int n = nums2.size();
        for(int i=max(0,k-n); i<=min(m,k); i++){
            vector<int> cand = merge(maxArray(nums1, i), maxArray(nums2, k-i));
            if(gt(cand,ret,0,0)) ret = cand;
            //cout<<i<<" "<<cand.size()<<" "<<ret.size()<<endl;
        }
        return ret;
    }
};

#endif /* _21_CreateMaximumNumber_h */
