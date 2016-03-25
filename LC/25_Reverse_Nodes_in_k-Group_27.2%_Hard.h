/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head || k<=1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* right = prev;
        
        while(right){
            
            ListNode* tmp = prev->next;
            int i=0;
            while(i<k){
                if(!right->next) return dummy->next;
                right = right->next;
                i++;
            }
            
            //if(right->next == NULL) return dummy->next;
            while(prev->next != right){
                ListNode* tmp1 = prev->next;
                prev->next = prev->next->next;
                ListNode* tmp2 = right->next;
                right->next = tmp1;
                tmp1->next = tmp2;
            }
            
            //i=0;
            //while(i<k){
            //    if(!prev->next) return dummy->next;
            //    prev = prev->next;
            //    i++;
            //}
            prev = tmp;
            right = prev;
        }
        return dummy->next;
    }
};