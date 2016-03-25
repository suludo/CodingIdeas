//
//  B.hpp
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/24/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef B_hpp
#define B_hpp

#include <stdio.h>
#include "A.hpp"

class B{
    int vb;
    A* a;
public:
    
    A* getA(){ return a;}
    inline void setB(int b){ vb = b;}
    void setA(int aa);// {a->setA(aa);}
};

#endif /* B_hpp */
