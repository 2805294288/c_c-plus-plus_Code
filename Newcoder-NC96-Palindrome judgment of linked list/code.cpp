/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast && fast->next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        ListNode *NewHead = slow;
        
        ListNode *Node = nullptr;
        ListNode *cur = NewHead;
        ListNode *Next = cur -> next;
        
        cur -> next = Node;
        while(Next)
        {
            Node = cur;
            cur = Next;
            Next = cur -> next;
            cur -> next = Node;
        }
        while(cur)
        {
            if(cur -> val != head ->val)
            {
                return false;
            }
            
            cur = cur -> next;
            head = head -> next;
        }
        
        return true;
    }
};












