//
//  233_NumberOfDigitOne.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _33_NumberOfDigitOne_h
#define _33_NumberOfDigitOne_h




class Solution {
public:
    int countDigitOne(int n) {
        int ret = 0;
        
        for(int64_t m = 1; m<=n; m*=10){
            //you only care about how many time 1 will appear
            //on this digit [h%10], so don't worry about
            //THE DUPLICATE OCCURRENCES THIS WOULD NEVER COUNT IN
            int h = n/m;
            int l = n%m;
            
            ret += m*(h/10);
            
            if(h%10>=2)
                ret += m;
            else if(h%10==1)
                ret += (l+1);
        }
        return ret;
    }
};


#endif /* _33_NumberOfDigitOne_h */
