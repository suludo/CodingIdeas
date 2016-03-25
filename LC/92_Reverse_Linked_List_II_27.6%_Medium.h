/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head || m>=n) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* p = head;
        ListNode* prev = dummy;
        ListNode* pn = NULL;
        int i=0;
        while(p){
            i++;
            if(i<m)
                prev = p;
            else if(i==n){pn = p;break;}
            p = p->next;
        }
        if(!pn) return head;
        
        while(prev->next != pn){
            ListNode* tmp1 = prev->next;
            ListNode* tmp2 = pn->next;
            
            prev->next = tmp1->next;
            pn->next = tmp1;
            tmp1->next = tmp2;
            
        }
        return dummy->next;
    }
};