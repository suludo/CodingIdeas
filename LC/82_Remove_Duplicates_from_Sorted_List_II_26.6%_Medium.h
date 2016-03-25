/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* p = head, *dup = NULL;
        while(p){
            if(p->next && p->val == p->next->val){
                dup = p;
                p->next = p->next->next;
            }
            else{
                if(dup){
                    prev->next = p->next;
                    dup = NULL;
                }
                else
                    prev = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};