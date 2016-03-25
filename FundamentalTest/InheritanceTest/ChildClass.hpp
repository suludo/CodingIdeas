//
//  ChildClass.hpp
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/24/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef ChildClass_hpp
#define ChildClass_hpp

#include <stdio.h>
#include "ParentClass.cpp"

class B: public A{
    int a;
public:
//    int a;
    int b;
//    
//    int c;
    
    B():A(){}
};
#endif /* ChildClass_hpp */
