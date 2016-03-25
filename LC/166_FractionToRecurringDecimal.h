//
//  166_FractionToRecurringDecimal.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _66_FractionToRecurringDecimal_h
#define _66_FractionToRecurringDecimal_h



class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ret;
        if(numerator==0) return to_string(0);
        if(denominator==0) return ret;
        bool neg = (numerator<0 && denominator>0) || (numerator>0 && denominator<0);
        
        int64_t n = numerator;
        int64_t d = denominator; //you have to do this to prevent overflow
        d = abs(d);
        n = abs(n);
        
        if(neg)
            ret+="-";
        ret+=to_string(n/d);
        if(n%d==0)  return ret;
        ret+=".";
        map<int, int> mp;
        for(int64_t r=n%d;r; r%=d){
            
            if(mp.count(r)>0){
                ret.insert(mp[r],1,'(');
                ret+=')';
                break;
            }
            
            mp[r] = ret.size();
            //cout<<r<<" ";
            //cout<<(r*10)/d<<endl;
            r*=10;
            ret+=to_string(r/d);
        }
        return ret;
    }
};


#endif /* _66_FractionToRecurringDecimal_h */
