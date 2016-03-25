//
//  125_ValidPalindrome.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _25_ValidPalindrome_h
#define _25_ValidPalindrome_h


//pay attn, comparison between alphabetical and numerical return false

class Solution {
public:
    bool isEqual(char a, char b){
        if(a<b) return isEqual(b, a);
        //pay attn
        if(isalpha(a)^isalpha(b)) return false;
        int offset = abs('A'-'a');
        return a==b || (a-offset)==b;
    }
    
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        if(l>=r) return true;
        while(l<=r){
            while(l<s.size() && !isalnum(s[l]))
                l++;
            while(r>=0 && !isalnum(s[r]))
                r--;
            
            if(l>r) return true;
            if(!isEqual(s[l],s[r]))
                return false;
            l++;
            r--;
        }
        return true;
        
    }
};


#endif /* _25_ValidPalindrome_h */
