//
//  155_MinStack.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _55_MinStack_h
#define _55_MinStack_h

class MinStack {
public:
    stack<int> buf;
    stack<int> minBuf;
    void push(int x) {
        if(minBuf.empty() || minBuf.top()>=x) minBuf.push(x);
        buf.push(x);
    }
    
    void pop() {
        if(buf.empty()) return;
        if(minBuf.top()==buf.top()) minBuf.pop();
        buf.pop();
    }
    
    int top() {
        return buf.top();
    }
    
    int getMin() {
        return minBuf.top();
    }
};


#endif /* _55_MinStack_h */
