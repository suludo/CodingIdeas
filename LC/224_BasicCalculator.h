//
//  224_BasicCalculator.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _24_BasicCalculator_h
#define _24_BasicCalculator_h



class Solution {
public:
    //"(1+(4+5+2)-3)+(6+8)" = 23
    int calculate(string s) {
        stack<int> nums, ops;
        
        int num = 0; //parser for the numbers
        int ret = 0; //store temp result
        int sign = 1;//current sign and those pushed into stack for track
        for(int i=0; i<s.size(); ++i){
            //if(s[i]==' ')
            //    continue;
            if(isdigit(s[i])){
                num = num*10 + (s[i]-'0');
            }
            else{
                ret += num*sign;
                num = 0;
                if(s[i]=='+'){
                    sign = 1;
                }
                else if(s[i]=='-'){
                    sign = -1;
                }
                //only when you open a parentheses do push the num and op
                else if(s[i]=='('){
                    nums.push(ret);
                    ops.push(sign);
                    ret = 0;
                    sign = 1;
                }
                else if(s[i]==')' && !ops.empty()){
                    //closing parentheses, get the number before encountering '('
                    //and the op as well, apply it with the value (ret) in () pairs
                    ret = ops.top()*ret + nums.top();
                    nums.pop();
                    ops.pop();
                }
            }
        }
        ret += sign*num;
        return ret;
    }
};

#endif /* _24_BasicCalculator_h */
