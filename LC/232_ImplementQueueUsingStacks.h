//
//  232_ImplementQueueUsingStacks.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _32_ImplementQueueUsingStacks_h
#define _32_ImplementQueueUsingStacks_h

class Queue {
public:
    stack<int> q;
    stack<int> cache;
    // Push element x to the back of queue.
    //store it in reverse order
    //i.e. last come to the bottom of the stack
    //i.e. top of the stack is always the oldest exising element
    void push(int x) {
        while(!q.empty()){
            cache.push(q.top());
            q.pop();
        }
        q.push(x);
        while(!cache.empty()){
            q.push(cache.top());
            cache.pop();
        }
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        if(q.empty()==false)
            q.pop();
    }
    
    // Get the front element.
    int peek(void) {
        if(q.empty()) return 0;
        return q.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return q.empty();
    }
};


#endif /* _32_ImplementQueueUsingStacks_h */
