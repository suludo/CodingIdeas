//
//  151_ReverseWordsInAString.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _51_ReverseWordsInAString_h
#define _51_ReverseWordsInAString_h

#include <string>
#include <iostream>
using namespace std;


//pay attn reverse sort range [begin, end)
class Solution {
public:
    void reverseWords1(string &s) {
        reverse(s.begin(), s.end());
        int start = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=' '){
                if(start>0) s[start++] = ' ';
                int j = i;
                while(j<s.size() && s[j]!= ' ') s[start++] = s[j++];
                reverse(s.begin()+start-(j-i), s.begin()+start);
                i = j;
            }
        }
        s.erase(s.begin()+start, s.end());
    }
    
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int start = 0, i=0, n = s.size();
        while(i<n){
            if(s[i] != ' '){
                int j=0;
                if(start!=0) s[start++] = ' ';
                while(i+j<n && s[i+j]!=' ') {
                    s[start] = s[i+j];
                    start++; j++;
                }
                reverse(s.begin()+start-j, s.begin()+start);
                i+=(j-1);
            }
            i++;
        }
        s.erase(s.begin()+start, s.end());
        cout<<s<<endl;
    }
    
    
};

void test(){
    Solution S;
    string s= "hi!";
    S.reverseWords(s);
}

#endif /* _51_ReverseWordsInAString_h */
