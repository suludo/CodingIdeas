//
//  215_KthLargestElementInAnArray.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _15_KthLargestElementInAnArray_h
#define _15_KthLargestElementInAnArray_h


#include <vector>
#include <random>

using namespace std;

class Solution1 {
public:
    int helper(vector<int>& nums, int s, int e, int k){
        if(s<0 || e>=nums.size() || s>e || k<=0) return -1;
        int p = s; //pivot
        int j = s; //runner
        while(j<=e){
            if(nums[j]>nums[p]){
                //p     j      p   j
                //3 2 1 5 => 5 2 1 3 => 5 3 1 2
                swap(nums[j], nums[p++]); //move j to the pivot location, pivot -> j
                swap(nums[j], nums[p]); //nums[j] which is the replaced nums[p] moves to the next of p
            }
            j++;
        }
        int dist = p-s+1;
        if(dist==k) return nums[s+dist-1];
        if(dist>k) return helper(nums, s, s+dist-2, k);
        return helper(nums, s+dist, e, k-dist);
    }
    int findKthLargest(vector<int>& nums, int k) {
        unsigned seed = 1;//std::chrono::system_clock::now().time_since_epoch().count();
        
        shuffle (nums.begin(), nums.end(), std::default_random_engine(seed));
        
        return helper(nums, 0, nums.size()-1, k);
    }
};

class Solution {
public:
    int helper(vector<int>& nums, int s, int e, int k){
        if(s<0 || e>=nums.size() || s>e || k<=0) return -1;
        int p = s; //pivot point
        int j = s; //runner
        while(j<=e){
            if(nums[j]>nums[e])
                swap(nums[j],nums[p++]);
            j++;
        }
        swap(nums[e],nums[p]);
        int dist = p-s+1;
        if(dist==k) return nums[s+dist-1];
        if(dist>k) return helper(nums, s, s+dist-2, k);
        return helper(nums, s+dist, e, k-dist);
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        unsigned seed = rand();//std::chrono::system_clock::now().time_since_epoch().count();
        
        //unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        
        shuffle (nums.begin(), nums.end(), std::default_random_engine(seed));
        
        return helper(nums, 0, nums.size()-1, k);
    }
};

#endif /* _15_KthLargestElementInAnArray_h */
