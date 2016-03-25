//
//  152_MaximumProductSubarray.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _52_MaximumProductSubarray_h
#define _52_MaximumProductSubarray_h


class Solution {
public:
    int maxProduct(vector<int>& A) {
        int maxProd, minProd;
        int ret = INT_MIN, n = A.size();
        for(int i=n-1; i>=0; i--){
            if(i==(n-1)){
                maxProd = A[i];
                minProd = A[i];
            }
            else if(A[i]==0){
                maxProd = minProd = 0;
            }
            else{
                int tmp = minProd;
                minProd=min(A[i], min(A[i]*minProd, A[i]*maxProd));
                maxProd=max(A[i], max(A[i]*tmp, A[i]*maxProd));
            }
            ret = max(ret, maxProd);
        }
        return ret;
    }
};

#endif /* _52_MaximumProductSubarray_h */
