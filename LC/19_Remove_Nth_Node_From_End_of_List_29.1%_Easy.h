/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head) return head;
        ListNode* first = head;
        ListNode* second = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for(int i=1; i<n; i++)
            second = second->next;
            
        while(first && second){
            if(!second->next) break;
            second = second->next;
            prev = first;
            first = first->next;
        }
        prev->next = first->next;
        first->next = NULL;
        delete first;
        return dummy->next;
    }
};