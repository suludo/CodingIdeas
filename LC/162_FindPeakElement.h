//
//  162_FindPeakElement.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _62_FindPeakElement_h
#define _62_FindPeakElement_h


//pay attn, mid compare to its neighbors, i.e. mid+1
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() <= 1) return 0;
        int mid = 0, l = 0, h = num.size() - 1;
        
        while (l < h) {
            mid = (l + h) / 2;
            if (num[mid] > num[mid + 1])
                h = mid;
            else if (num[mid] < num[mid + 1])
                l = mid + 1;
        }
        
        return h;
    }
};


#endif /* _62_FindPeakElement_h */
