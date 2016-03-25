//
//  146_LRUCache.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _46_LRUCache_h
#define _46_LRUCache_h

// pay attn to the content of node and LRUCache
//when new node is added, it's added to the tail
//when node is moved due to overflow, it's removeing from the head

struct node{
    int k;
    int kv;
    node* prev;
    node* next;
    node(int _k, int _kv):k(_k),kv(_kv),prev(NULL),next(NULL){};
};

class LRUCache{
    
public:
    int cp;
    unordered_map<int, node*> mp;
    node* head;
    node* tail;
    LRUCache(int capacity) {
        cp = capacity;
        mp.clear();
        head = tail = NULL;
    }
    
    void insert(node* n){
        if(!n) return;
        if(!head){
            head = n;
            tail = head;
        }
        else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    //remove any node in the doubly linked list
    void rm(node* n){
        if(!n) return;
        if(head==n){
            head = head->next;
            if(head) head->prev = NULL;
            else tail = NULL;
        }
        else if(tail==n){ //indicating head and tail are different; why? => n!=head && n==tail
            tail = tail->prev;
            tail->next = NULL;
        }
        else{
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
        delete n;
        n = nullptr;
    }
    //move node to the tail of the doubly linked list
    void move(node* n){
        if(!n) return;
        if(tail==n) return;
        if(n!=head){
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
        else{
            head->next->prev = NULL;
            head = head->next;
            //head = head->next;
            //head->prev = NULL;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        move(mp[key]);
        return mp[key]->kv;
    }
    
    void set(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(mp.size()==cp){
                //pay attn, this line can't be placed here,
                //if capacity is 1, the head is removed , it will become NULL
                //which will cause crash
                //rm(head);
                mp.erase(head->k);
                rm(head);
            }
            node* n = new node(key,value);
            insert(n);
            mp[key] = n;
        }
        else{
            mp[key]->kv = value;
            move(mp[key]);
        }
    }
};

#endif /* _46_LRUCache_h */
