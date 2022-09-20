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
private:
    int getLength(ListNode* head)
    {
        int count = 0;
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* getNthNode(ListNode* head, int n)
    {
        int count = 1;
        ListNode* temp = head;
        while(temp)
        {
            if(count == n)
            {
                return temp;
            }
            temp = temp->next;
            count++;
        }
        return NULL;
    }
    ListNode* reverse(ListNode* head)
    {
        if(!head or !head->next)
            return head;
        
        ListNode* cur = head;
        ListNode* nxt = head->next;
        ListNode* reversedHead = reverse(nxt);
        cur->next = NULL;
        nxt->next = cur;
        return reversedHead;
    }
    ListNode* merge(ListNode* l, ListNode* r)
    {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        
        while(l and r)
        {
            dummy->next = l;
            dummy = dummy->next;
            l = l->next;
            dummy->next = r;
            dummy = dummy->next;
            r = r->next;
        }
        if(l)
        {
            dummy->next = l;
        }   
        else
        {
            dummy->next = r;
        }
        
        return temp->next;
    }
public:
    void reorderList(ListNode* head)
    {
        //len 0,1,2
        if(!head or !head->next or !head->next->next)
        {
            return;
        }
        
        int length = getLength(head); 
        int mid = (length+1)/2;
        
        ListNode* midNode = getNthNode(head, mid);
        
        ListNode* next = midNode->next;
        midNode->next = NULL;
        
        ListNode* reversedRightHalf = reverse(next);
        
        head = merge(head,reversedRightHalf);
    }
};