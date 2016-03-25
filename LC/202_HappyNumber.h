//
//  202_HappyNumber.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _02_HappyNumber_h
#define _02_HappyNumber_h


/*Write an algorithm to determine if a number is "happy".
 
 A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 
 Example: 19 is a happy number
 
 12 + 92 = 82
 82 + 22 = 68
 62 + 82 = 100
 12 + 02 + 02 = 1*/

class Solution {
public:
    int sqSum(int n){
        int res = 0;
        while(n){
            res += (n%10)*(n%10);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> dict;
        while(n!=1){
            n = sqSum(n);
            if(dict.find(n)!=dict.end())
                return false;
            dict.insert(n);
        }
        return true;
    }
    //https://en.wikipedia.org/wiki/Happy_number
    //When the algorithm ends in a cycle of repeating numbers, this cycle always includes the number 4, so it is not even necessary to store previous numbers in the sequence:
    bool isHappy(int n) {
        int num=0;
        while(n!=1&&n!=4)
        {
            while(n)
            {
                num += (n%10) * (n%10);
                n/=10;
            }
            n=num;num=0;
        }
        return 1==n;
    }
};

#endif /* _02_HappyNumber_h */
