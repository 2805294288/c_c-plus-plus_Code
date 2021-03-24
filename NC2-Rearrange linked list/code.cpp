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
    void reorderList(ListNode *head) {
        if(head == nullptr || head -> next == nullptr || head->next->next == nullptr)
        {
            return;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast -> next)
        {
            fast = fast -> next  -> next;
            slow = slow -> next;
        }
        
        ListNode *HNode = slow -> next;
        slow -> next = nullptr;
        
        ListNode* Node = nullptr;
        ListNode* cur = HNode;
        ListNode* Next = cur -> next;
        
        cur -> next = Node;
        while(Next)
        {
            Node = cur;
            cur = Next;
            Next = cur -> next;
            cur -> next = Node;
        }
        
        ListNode *CurHead = head;
        ListNode *NewHead = cur;
        ListNode *Next1 = head;
        ListNode *Next2 = NewHead;
        
        while(Next2)
        {
            Next1 = CurHead -> next;
            Next2 = NewHead -> next;
            CurHead -> next = NewHead;
            NewHead -> next = Next1;
            CurHead = Next1;
            NewHead = Next2;
        }
    }
};













