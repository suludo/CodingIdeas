//
//  273_IntegerToEnglishWords.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/18/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _73_IntegerToEnglishWords_h
#define _73_IntegerToEnglishWords_h


/*
 Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
 
 For example,
 123 -> "One Hundred Twenty Three"
 12345 -> "Twelve Thousand Three Hundred Forty Five"
 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 */


class Solution {
public:
    vector<string>mp;
    vector<string> postfix;
    Solution(){
        mp = {"Zero", "One", "Two", "Three","Four", "Five", "Six","Seven", "Eight", "Nine","Ten", "Eleven", "Twelve","Thirteen", "Fourteen", "Fifteen","Sixteen", "Seventeen", "Eighteen","Nineteen", "Twenty", "Thirty","Forty", "Fifty", "Sixty","Seventy", "Eighty", "Ninety"};
        postfix = {"Thousand","Million","Billion"};
        // mp.push_back("Zero"); //0
        // mp.push_back("One");
        // mp.push_back("Two");
        // mp.push_back("Three");
        // mp.push_back("Four");
        // mp.push_back("Five");
        // mp.push_back("Six");
        // mp.push_back("Seven");
        // mp.push_back("Eight");
        // mp.push_back("Nine"); //9
        // mp.push_back("Ten");  //10
        // mp.push_back("Eleven");
        // mp.push_back("Twelve");
        // mp.push_back("Thirteen");
        // mp.push_back("Fourteen");
        // mp.push_back("Fifteen");
        // mp.push_back("Sixteen");
        // mp.push_back("Seventeen");
        // mp.push_back("Eighteen");
        // mp.push_back("Nineteen");   //19
        // mp.push_back("Twenty");     //20
        // mp.push_back("Thirty");     //21
        // mp.push_back("Forty");
        // mp.push_back("Fifty");
        // mp.push_back("Sixty");
        // mp.push_back("Seventy");
        // mp.push_back("Eighty");
        // mp.push_back("Ninety");
        
        //postfix.push_back("Thousand");
        //postfix.push_back("Million");
        //postfix.push_back("Billion");
    }
    string helper(int n, int flag) {//0 ones, 1 thousands, 2 millions, 3 billions
        string ret;
        if(n>=1000 || n<0) return ret;
        if(n==0) return "Zero";
        
        int ones = n%10;
        int tens = (n/10)%10;
        int hundreds = n/100;
        
        int sum2 = n%100; //tens*10 + ones;
        
        if(hundreds)
            ret += (mp[hundreds]+" Hundred");
        if(sum2>0){
            if(hundreds)
                ret += " ";
            if(sum2>20){
                ret += mp[20+tens-2];
                if(ones){
                    ret += " ";
                    ret += mp[ones];
                }
            }
            else if(sum2>=10){ //10~19
                ret += mp[sum2];
            }
            else{ //1~9
                ret += mp[sum2];
            }
        }
        if(flag){
            ret += " ";
            ret += postfix[flag-1];
        }
        return ret;
    }
    
    string numberToWords(int num) {
        
        if(num==0) return "Zero";
        int ones = num%1000;
        int thousands = (num/1000)%1000;
        int millions = (num/1000000)%1000;
        int billions = (num/1000000000);
        
        string ret;
        if(billions)
            ret += helper(billions, 3);
        if(millions){
            if(ret.empty() == false)
                ret+= " ";
            ret += helper(millions, 2);
        }
        if(thousands){
            if(ret.empty() == false)
                ret+= " ";
            ret += helper(thousands, 1);
        }
        if(ones){
            if(ret.empty() == false)
                ret+= " ";
            ret += helper(ones, 0);
        }
        
        return ret;
    }
};

#endif /* _73_IntegerToEnglishWords_h */
