//
//  ConditionVariable.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef ConditionVariable_h
#define ConditionVariable_h

#include <deque>
#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
using namespace std;

mutex mu;
deque<int> dq;
condition_variable cond;
//condition_variable cond1;

void pushQ(){
    int input = 0;
    while(1){
        if(!(cin>>input)){
            //http://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            continue;
        }
        cout<<input<<endl;
        if(input<0){
            //cond1.notify_one();
            break;
        }
        
        unique_lock<mutex> locker(mu);
        dq.push_back(input);
        locker.unlock();
        cout<<"in the queue: "<<dq.size()<<" elems: ";
        for(auto it=dq.begin(); it!=dq.end();it++)
            cout<<*it<<" ";
        cout<<endl;
        cond.notify_one();
        //std::this_thread::sleep_for(chrono::seconds(1));
    }
    cout<<"quit pushQ!"<<endl;
}

void procQ(){

    unsigned int seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    while(1){
        unique_lock<mutex> locker(mu);
        
        cond.wait(locker, [&]()->bool{return !dq.empty();});
        int data = dq.front();
        dq.pop_front();
        locker.unlock();
        
        
        std::this_thread::sleep_for(chrono::milliseconds(e()%2000));
        cout<<"all right";
        cout<<" processed data "<<data<<endl;
    }
}


void test(){
    
    thread t1(pushQ);
    thread t2(procQ);
    t1.detach();
    t2.join();
    
    
}

#endif /* ConditionVariable_h */
