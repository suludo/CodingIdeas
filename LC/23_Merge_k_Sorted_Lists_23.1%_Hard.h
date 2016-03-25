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
 class Comp{
public:
     bool operator() (const ListNode* a, const ListNode* b) const{
         return a->val > b->val;
     }
     
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> q;
        for(int i=0; i<lists.size(); i++)
            if(lists[i])
                q.push(lists[i]);
        //int len = q.size();
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        
        while(!q.empty()){
            prev->next = q.top();
            prev = prev->next;
            if(q.top()->next) q.push(q.top()->next);
            q.pop();
        }
        prev->next = NULL;
        
        return dummy->next;
    }
};


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
    ListNode* helper(vector<ListNode*> &lists, int start, int end){
        if(start>end) return NULL;
        if(start == end) return lists[start];
        int mid = (start+end)/2;
        ListNode* n1 = helper(lists, start, mid);
        ListNode* n2 = helper(lists, mid+1, end);
        if(!n1) return n2;
        if(!n2) return n1;
        
        ListNode* p1 = n1;
        ListNode* p2 = n2;
        ListNode* ret = NULL;
        ListNode* prev = NULL;
        while(p1 && p2){
            ListNode* cur = p1->val<=p2->val ? p1:p2;
            if(!ret) ret = cur;
            else prev->next = cur;
            if(p1->val<=p2->val) p1 = p1->next;
            else p2 = p2->next;
            prev = cur;
        }
        if(p1) prev->next = p1;
        else prev->next = p2;
        return ret;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return helper(lists, 0, lists.size()-1);
    }
};