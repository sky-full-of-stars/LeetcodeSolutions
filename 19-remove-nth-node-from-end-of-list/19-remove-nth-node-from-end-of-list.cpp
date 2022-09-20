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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(!head->next)
            return NULL;
        
        ListNode* first = head;
        ListNode* second = head;
        ListNode* prev = NULL;
        while(n--)
        {
            second = second->next;
        }
        while(second)
        {
            second = second->next;
            prev = first;
            first = first->next;
        }
        
        if(prev and prev->next)    
            prev->next = prev->next->next;
        if(first == head)
            head = first->next;
        
        return head;
    }
};