//
//  241_DifferentWaysToAddParentheses.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _41_DifferentWaysToAddParentheses_h
#define _41_DifferentWaysToAddParentheses_h


class Solution {
public:
    
    bool isOp(char c){
        return (c=='+' || c=='-' || c=='*' || c=='/');
    }
    bool isNum(string s, int &val){
        for(int i=0; i<s.size(); i++){
            if(isOp(s[i])) return false;
            val = val*10 + s[i]-'0';
        }
        return true;
    }
    vector<int> diffWaysToCompute(string s) {
        vector<int> ret;
        int val = 0;
        if(isNum(s, val)){
            ret.push_back(val);
        }
        else{
            for(int ii=0; ii<s.size(); ii++){
                if(isOp(s[ii])){
                    vector<int> l = diffWaysToCompute(s.substr(0,ii));
                    vector<int> r = diffWaysToCompute(s.substr(ii+1));
                    //cout<<"split "<<s.substr(0,ii).c_str()<< " and "<<s.substr(ii+1).c_str()<<endl;
                    for(int i=0; i<l.size(); i++){
                        for(int j=0; j<r.size(); j++){
                            if(s[ii]=='+')
                                ret.push_back(l[i]+r[j]);
                            
                            else if(s[ii]=='-')
                                ret.push_back(l[i]-r[j]);
                            
                            else if(s[ii]=='*')
                                ret.push_back(l[i]*r[j]);
                            
                            else if(s[ii]=='/' && r[j]!=0)
                                ret.push_back(l[i]/r[j]);
                            
                        }
                    }
                }
            }
        }
        return ret;
    }
};

#endif /* _41_DifferentWaysToAddParentheses_h */
