/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int aux = 0;
        int sum = 0;
        ListNode* head = NULL;
        ListNode* prev = NULL;
        while(l1 || l2){
            int val1 = l1 ? l1->val:0;
            int val2 = l2 ? l2->val:0;
            
            sum = (val1+val2+aux);
            aux = sum/10;
            sum = sum%10;
            
            ListNode* n = new ListNode(sum);
            if(!prev)
                head = n;
            else
                prev->next = n;
                
            prev = n;
            l1 = l1 ? l1=l1->next:NULL;
            l2 = l2 ? l2=l2->next:NULL;
        }
        if(aux)
            prev->next = new ListNode(aux);
        return head;
    }
};