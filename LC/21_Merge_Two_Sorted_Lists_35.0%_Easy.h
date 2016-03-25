/*

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* newHead = NULL;
        ListNode* prev = NULL;
        while(l1 || l2){
            ListNode* n = NULL;
            if(l1&&l2) n = l1->val>l2->val ? l2:l1;
            else n = l1 ? l1:l2;
            
            if(!newHead) newHead = n;
            else prev->next = n;
            prev = n;
            if(n==l1) l1 = l1->next;
            else l2 = l2->next;
        }
        return newHead;
    }
};