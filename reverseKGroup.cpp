/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
    void reverse(ListNode*& start, ListNode*& end) {
        ListNode* prev = NULL;
        ListNode* curr = start;
        ListNode* nxt = start->next;
        
        while(prev != end) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt) nxt = nxt->next;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head || !head->next || k == 1)  return head;
        
        ListNode* start = head;
        ListNode* end = head;
        int inc = k-1;
        while(inc--) {
            end = end->next;
            if(!end)    return head;
        }
        ListNode* newHead = reverseKGroup(end->next, k);
        reverse(start, end);
        start->next = newHead;
        
        return end;
    }
};