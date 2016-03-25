//
//  Singleton.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef Singleton_h
#define Singleton_h


//
//  main.cpp
//  SingletonExample
//
//  Created by Xiaorui Zhao on 12/13/15.
//  Copyright © 2015 Xiaorui Zhao. All rights reserved.
//

#include <iostream>

using namespace std;

//http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
//http://stackoverflow.com/questions/270947/can-any-one-provide-me-a-sample-of-singleton-in-c/271104#271104

class S
{
public:
    static S& getInstance()
    {
        static S instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    void setValue(int m){m_val = m;}
    int getValue(){return m_val;}
private:
    int m_val;
    S() {}                // Constructor? (the {} brackets) are needed here.
    //http://www.learncpp.com/cpp-tutorial/85-constructors/
    //However, if you do have other non-default constructors in your class, but no default constructor, C++ will not create an empty default constructor for you. In this case, the class will not be instantiatiable without parameters.
    //S(int a):m_val(a){}
    ~S() {cout<<"just tried to call dtor"<<endl;}
    
    // C++ 03
    // ========
    // Dont forget to declare these two. You want to make sure they
    // are unacceptable otherwise you may accidentally get copies of
    // your singleton appearing.
    //S(S const&);              // Don't Implement
    //void operator=(S const&); // Don't implement
    
    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
public:
    //DEFAULT AND DELETE
    //http://stackoverflow.com/questions/5513881/meaning-of-delete-after-function-declaration
    //The common idiom of "prohibiting copying" can now be expressed directly:
    //S(S const&)               = delete;
    //void operator=(S const&)  = delete;
    
    //When declaring a const variable, it is possible to put const either before or after the type:
    S(const S&) = delete;
    void operator=(const S&) = delete;
    
    
    //http://stackoverflow.com/questions/9209994/method-declared-in-class-but-not-defined
    //if you just declare without calling it in the main
    // the program will run fine
    void justDoIt();
    //REF:
    /*
     Note that the linker needs to link only those symbols which are used by your program,
     For ex: If your program declares a function, provides no definition & then never uses/calls the function anywhere, the linker does not need to embed the code for jumping to the address where the object code for the function resides at any function call site.
     Given such a scenario the the linker will simply never need to lookup for the function definition at all, Hence the code will compile and link fine.
     */
    
    // Note: Scott Meyers mentions in his Effective Modern
    //       C++ book, that deleted functions should generally
    //       be public as it results in better error messages
    //       due to the compilers behavior to check accessibility
    //       before deleted status
};


int main()
{
    //S *a = &S::getInstance();
    //a->setValue(0);
    //cout<<"haha: "<<a->getValue()<<endl;
    S &a  = S::getInstance();
    cout<<a.getValue()<<endl;
    //But once justDoIt is called, it will cause link error
    //a.justDoIt();  //THIS WILL CAUSE LINK ERROR
    //Defining the function method in the class will eliminate this error
    //void justDoIt(){}
    
    return 0;
}

#endif /* Singleton_h */
