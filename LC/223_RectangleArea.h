//
//  223_RectangleArea.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _23_RectangleArea_h
#define _23_RectangleArea_h



class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int h1 = D-B;
        int h2 = H-F;
        int w1 = C-A;
        int w2 = G-E;
        
        int total = h1*w1+h2*w2;
        
        
        
        if(D<=F || B>=H || C<=E || A>=G)
            return total;
        
        int h = 0;
        int w = 0;
        
        if(E>A)
            if(C>=G)
                w = w2;
            else
                w = C-E;
        else
            if(C<=G)
                w=w1;
            else
                w = G-A;
        
        
        if(F>B)
            if(D>=H)
                h = h2;
            else
                h = D-F;
        else
            if(D<=H)
                h = h1;
            else
                h = H-B;
        
        return total - h*w;
    }
};

#endif /* _23_RectangleArea_h */
