//
//  150_EvaluateReversePolishNotation.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _50_EvaluateReversePolishNotation_h
#define _50_EvaluateReversePolishNotation_h


/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 
 Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 
 Some examples:
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6*/



class Solution {
public:
    bool isOp(string s){
        if(s.size()!=1) return false;
        return (s[0]=='+' || s[0]=='-' || s[0]=='*' || s[0]=='/');
    }
    int parseNum(string s, bool &status){
        int ret = 0;
        int base = 1;
        int sign = 1;
        if(s[0]=='+')
            s = s.substr(1);
        if(s[0]=='-')
        {
            sign = -1;
            s = s.substr(1);
        }
        for(int i=0; i<s.size(); i++){
            char c = s[s.size()-i-1];
            if(c<'0' || c>'9') {
                status=false;
                return 0;
            }
            ret += base*(c-'0');
            base*=10;
        }
        status = true;
        return ret*sign;
    }
    int evalRPN(vector<string> &tokens) {
        int ret = 0;
        stack<int> s;
        int csum = tokens.size();
        int i=0;
        while(i<csum){
            if(!isOp(tokens[i])){ //not operator, take it as num
                bool status = true;
                int num = parseNum(tokens[i],status);
                if(status)
                    s.push(num);
                else
                    return 0;
            }
            else{ // is an operator
                if(s.empty()) return 0;
                int second = s.top();
                s.pop();
                if(s.empty()) return 0;
                int first = s.top();
                s.pop();
                
                if(tokens[i][0]=='+')
                    ret = first+second;
                else if(tokens[i][0]=='-')
                    ret = first-second;
                else if(tokens[i][0]=='*')
                    ret = first*second;
                else if(second && tokens[i][0]=='/')
                    ret = first/second;
                else
                    return 0;
                
                s.push(ret);
            }
            i++;
        }
        return s.top();
    }
};

#endif /* _50_EvaluateReversePolishNotation_h */
