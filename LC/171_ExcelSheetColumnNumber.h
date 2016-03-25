//
//  171_ExcelSheetColumnNumber.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _71_ExcelSheetColumnNumber_h
#define _71_ExcelSheetColumnNumber_h



class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        int base = 1;
        int ret = 0;
        for(int i=n-1; i>=0; i--){
            int num = (s[i]-'A')+1;
            ret += base*num;
            base *= 26;
        }
        return ret;
    }
};

#endif /* _71_ExcelSheetColumnNumber_h */
