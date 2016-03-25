//
//  165_CompareVersionNumbers.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _65_CompareVersionNumbers_h
#define _65_CompareVersionNumbers_h



class Solution {
public:
    string getNext(string s){
        for(int i=0; i<s.size(); i++)
            if(s[i]=='.') return s.substr(i+1);
        //return "";
        return "0";
    }
    int compareVersion(string version1, string version2) {
        while(version1!=version2){
            int v1 = stoi(version1);
            int v2 = stoi(version2);
            if(v1!=v2)
                return v1>v2 ? 1:-1;
            version1 = getNext(version1);
            version2 = getNext(version2);
        }
        return 0;
    }
};



#endif /* _65_CompareVersionNumbers_h */
