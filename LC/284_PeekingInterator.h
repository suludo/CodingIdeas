//
//  284_PeekingInterator.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/17/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _84_PeekingInterator_h
#define _84_PeekingInterator_h



// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    bool peeked;
    int cache;
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        peeked = false;
        
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        cache = peeked ? cache : Iterator::next();
        peeked = true;
        return cache;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ret = peeked ? cache : Iterator::next();
        peeked = false;
        return ret;
    }
    
    bool hasNext() const {
        return peeked || Iterator::hasNext();
    }
};


//https://leetcode.com/discuss/59415/simple-solution-line-method-without-extra-member-variables






#endif /* _84_PeekingInterator_h */
