//
//  ParentClass.hpp
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/24/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef ParentClass_hpp
#define ParentClass_hpp

#include <stdio.h>


class A{
public:
    int a;
    A(){
        a = -1;
        b = 1;
        c = 2;
    }
private:
    int b;
protected:
    int c;
};

#endif /* ParentClass_hpp */
