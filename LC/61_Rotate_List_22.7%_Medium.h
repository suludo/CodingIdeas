/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k<=0) return head;
        int len = 0;
        ListNode* p = head;
        ListNode* tail = NULL;
        while(p){
            ++len;
            if(!p->next) tail = p;
            p = p->next;
        }
        if(k%len==0) return head;
        k = k%len;
        k = len-k-1;
        p = head;
        while(k){
            p = p->next;
            --k;
        }
        ListNode* newHead = p->next;
        p->next = NULL;
        tail->next = head;
        return newHead;
    }
};