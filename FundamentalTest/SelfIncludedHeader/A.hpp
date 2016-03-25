//
//  A.hpp
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/24/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef A_hpp
#define A_hpp

#include <stdio.h>


class B;

class A{
    B* b;
    int va;
public:
    //IF YOU ALREADY DEFINED CUSTOMIZED CTOR, YOU HAVE TO
    //MANUALLY PROVIDE DEFAULT CTOR, OTHER WISE INITING A OBJCT WITH NO ARGUMENT
    //WILL CAUSE ERROR
    A():b(nullptr),va(0){}
    A(B* bb, int aa):b(bb),va(aa){}
    
    inline B* getB(){ return b;}
    void setB(int val);
    void setA(int val){va = val;}
};

#endif /* A_hpp */
