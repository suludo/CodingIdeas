//
//  227_BasicCalculator.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _27_BasicCalculator_h
#define _27_BasicCalculator_h

#include <string>
#include <iostream>
#include <climits>
using namespace std;



class Solution {
public:
    int calculate(string s) {
        int ret = 0, cur = 0;
        char op = '+';
        
        for(int i=0; i<s.size(); i++){
            if(s[i]==' ') continue;
            if(isdigit(s[i])){
                //j is the #digits to form a valid number from digit i inclusive
                int j = 0, tmp = 0;
                while(i+j<s.size() && isdigit(s[i+j])){
                    tmp = tmp*10 + (s[i+j]-'0');
                    j++;
                }
                if(s[i]=='0'&&j>1) return INT_MIN;
                switch(op){
                    case '+': cur += tmp; break;
                    case '-': cur -= tmp; break;
                    case '*': cur *= tmp; break;
                    case '/':
                        if(tmp == 0 ) return INT_MIN;
                        cur /= tmp;
                        break;
                }
                //TRICKY -- j-1 INSTEAD OF j
                //i will self increment in the end
                i+=(j-1);
            }
            else{
                if(s[i]=='+' || s[i]=='-'){
                    ret += cur;
                    cur = 0;
                }
                else if(s[i]!='*' && s[i]!='/') return INT_MIN;
                op = s[i];
            }
        }
        return ret+cur;
    }
};


void test(){
    Solution s;
    cout<<s.calculate("0-2147483647");
    cout<<endl;
}


#endif /* _27_BasicCalculator_h */
