//
//  168_ExcelSheetColumnTitle.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _68_ExcelSheetColumnTitle_h
#define _68_ExcelSheetColumnTitle_h




class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while(n>0){
            ret += 'A'+(n-1)%26;
            n = (n-1)/26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


#endif /* _68_ExcelSheetColumnTitle_h */
