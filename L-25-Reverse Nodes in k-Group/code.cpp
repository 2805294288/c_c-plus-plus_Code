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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* HeadNode = new ListNode();
        HeadNode->next = nullptr;
        ListNode* MNode = HeadNode;

        ListNode* SNode = head;
        int size = 0;
        while(SNode)
        {
            size++;
            SNode = SNode -> next;
        }
        int count = size / k;
        ListNode *Node1 = head;
        ListNode *Node2 = Node1;
        int n = 0;
        ListNode * NextNode = nullptr;
        ListNode* Node = nullptr;
        ListNode* Cur = nullptr;
        ListNode* Next = nullptr;

        while(count--)
        {
            n = k;
            while(--n)
            {
                Node2 = Node2 -> next;
            }
            NextNode = Node2->next;

            Node = nullptr;
            Cur = Node1;
            Next = Cur->next;
            
            Cur->next = Node;
            while(Next != NextNode)
            {
                Node = Cur;
                Cur = Next;
                Next = Cur->next;
                Cur -> next = Node;
            }
            MNode -> next = Node2;
            MNode = Node1;
            Node1 -> next = NextNode;
            Node1 = NextNode;
            Node2 = Node1;
        }
        return HeadNode->next;
    }
};








