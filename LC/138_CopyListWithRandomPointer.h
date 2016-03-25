//
//  138_CopyListWithRandomPointer.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _38_CopyListWithRandomPointer_h
#define _38_CopyListWithRandomPointer_h



/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList1(RandomListNode *head) {
        map<RandomListNode*, RandomListNode*> mp;
        mp[NULL] = NULL;
        RandomListNode* p = head;
        RandomListNode* prev = NULL;
        RandomListNode* newHead = NULL;
        RandomListNode* pp = NULL;
        
        while(p){
            
            RandomListNode* newNode = new RandomListNode(p->label);
            if(!newHead) newHead = newNode;
            mp[p] = newNode;
            if(prev)
                prev->next = newNode;
            prev = newNode;
            p = p->next;
        }
        
        p = head;
        pp = newHead;
        while(p){
            pp->random = mp[p->random];
            p = p->next;
            pp = pp->next;
        }
        return newHead;
    }
};


//https://leetcode.com/discuss/22421/solution-constant-space-complexity-linear-time-complexity
//The idea is to associate the original node with its copy node in a single linked list. In this way, we don't need extra space to keep track of the new nodes.
/*The algorithm is composed of the follow three steps which are also 3 iteration rounds.
 
1 Iterate the original list and duplicate each node. The duplicate of each node follows its original immediately.
2 Iterate the new list and assign the random pointer for each duplicated node.
3 Restore the original list and extract the duplicated nodes.
*/


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode * head) {
        RandomListNode * head_cp = nullptr, * cur = head, * cur_cp = nullptr;
        if (head == nullptr)
            return nullptr;
        while (cur != nullptr)
        {
            cur_cp = new RandomListNode (cur->label);
            cur_cp->next = cur->next;
            cur->next = cur_cp;
            cur = cur_cp->next;
        }
        cur = head;
        while (cur != nullptr)
        {
            cur_cp = cur->next;
            if (cur->random)
                cur_cp->random = cur->random->next;
            cur = cur_cp ->next;
        }
        cur = head;
        head_cp = head->next;
        while (cur != nullptr)
        {
            cur_cp = cur->next;
            cur->next = cur_cp->next;
            cur = cur->next;
            if (cur)
                cur_cp->next = cur->next;
        }
        return head_cp;
    }
};
#endif /* _38_CopyListWithRandomPointer_h */
