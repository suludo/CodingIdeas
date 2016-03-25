//
//  164_MaximumGap.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _64_MaximumGap_h
#define _64_MaximumGap_h



class Solution {
public:
    int getMax(vector<int> &num){
        int ret = INT_MIN;
        for(int i=0; i<num.size(); i++)
            ret = max(ret, num[i]);
        return ret;
    }
    void countSort(vector<int> &num, int nd){
        int n = num.size();
        vector<int> output(n, 0);
        vector<int> count(10, 0);
        
        for(int i=0; i<n; i++)
            count[(num[i]/nd)%10]++;
        
        for(int i=1; i<10; i++)
            count[i] += count[i-1];
        
        for(int i=(n-1); i>=0; i--)
            output[ --count[(num[i]/nd)%10] ] = num[i];
        
        for(int i=0; i<n; i++)
            num[i] = output[i];
        
    }
    
    void radixSort(vector<int> &num){
        int m = getMax(num);
        for(int nd=1; m/nd>0; nd*=10)
            countSort(num, nd);
    }
    int maximumGap(vector<int> &num) {
        if(num.size()<2) return 0;
        
        radixSort(num);
        int ret = 0;
        for(int i=1; i<num.size(); i++)
            ret = max(ret, abs(num[i]-num[i-1]));
        return ret;
    }
};
#endif /* _64_MaximumGap_h */
