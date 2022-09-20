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
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return head;
        
        ListNode* cur = head;
        ListNode* nxt = head->next;
        ListNode* reversedHead =  reverseList(nxt);
        nxt->next = cur;
        cur->next = NULL;
        
        return reversedHead;
    }
    
};