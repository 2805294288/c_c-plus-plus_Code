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
     * @param head ListNode类 
     * @param x int整型 
     * @return ListNode类
     */
    ListNode* partition(ListNode* head, int x) {
        ListNode* Xnode = new ListNode(0);
        ListNode* Dnode = new ListNode(0);
        ListNode* MXnode = Xnode;
        ListNode* MDnode = Dnode;
        
        while(head)
        {
            if(head->val < x)
            {
                MXnode -> next = head;
                MXnode = MXnode->next;
            }
            else
            {
                MDnode -> next = head;
                MDnode = MDnode -> next;
            }
            head = head -> next;
        }
        
        MXnode -> next = Dnode -> next;
        MDnode -> next = nullptr; //分开为两部分 但是要让后一个指向空。以免大的后一个还有别的指向
        
        ListNode* ret = Xnode -> next;
        delete Xnode;
        delete Dnode;
        
        return ret;
    }
};


















