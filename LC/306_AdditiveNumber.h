//
//  306_AdditiveNumber.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/14/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _06_AdditiveNumber_h
#define _06_AdditiveNumber_h

class Solution {
public:
    string add(string a, string b){
        if(a.empty()) return b;
        if(b.empty()) return a;
        int la = a.size(), lb = b.size();
        if(la>lb) return add(b,a);
        int aux = 0;
        string sum;
        while(la>0 || lb>0){
            int da = 0, db=0;
            if(la>0)
                da = a[--la]-'0';
            db = b[--lb]-'0';
            int tmp = da+db+aux;
            aux = tmp/10;
            tmp %=10;
            sum += ('0'+tmp);
        }
        if(aux) sum+='1';
        reverse(sum.begin(), sum.end());
        return sum;
    }
    //added this line to the latest submission
    bool isInValidString(string s){
        return (s.size()>1 && s[0]=='0');
    }
    bool check(string s1, string s2, string s3){
        if(isInValidString(s1) || isInValidString(s2) || isInValidString(s3)) return false;
        string sum = add(s1, s2);
        if(sum==s3) return true;
        if(s3.size()<=sum.size() || sum!=s3.substr(0, sum.size())) return false;
        return check(s2,s3.substr(0,sum.size()),s3.substr(sum.size()));
    }
    bool isAdditiveNumber(string num) {
        for(int i=1; i<=(num.size()/2); i++){
            for(int j=1; j<=(num.size()-i)/2; j++)
                if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))){
                    cout<<"at "<<i<<" "<<j<<endl;
                    return true;
                }
        }
        return false;
    }
};

#endif /* _06_AdditiveNumber_h */
