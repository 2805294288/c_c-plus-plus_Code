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
    ListNode *detectCycle(ListNode *head) {
        
        if(head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *point = nullptr;
        int count = 1;
        ListNode *RmNode =  nullptr;
        
        while(fast && fast->next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
            {
                point = fast;
                break;
            }
        }
        
        if(point == nullptr)
        {
            return nullptr;
        }
        
        RmNode = point->next;
        while(RmNode != point)
        {
            count++;
            RmNode = RmNode -> next;
        }
        
        ListNode *Rnode1 = head;
        ListNode *Rnode2 = head;
        
        while(count)
        {
            Rnode1 = Rnode1 -> next;
            count--;
        }
        
        while(1)
        {
            if(Rnode1 == Rnode2)
            {
                return Rnode2;
            }
            Rnode1 = Rnode1 -> next;
            Rnode2 = Rnode2 -> next;
        }
        
        return nullptr;
    }
};













