/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //这个题很好的考验了对链表的各种基本操作。
typedef struct ListNode ListNode;
void reorderList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    //用快慢指针找到中间结点。
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    //将中间结点的下一个作为新节点的头    
    ListNode* Node = slow->next;
    ListNode* prev = NULL;
    ListNode* Next = Node;
    slow->next = NULL;//中间结点必定是最后一个，在上面引用完中间结点以后，中间结点->next置NULL；
//对中间结点的下一个进行链表反转
    while (Node) {
        Next = Node->next;
        Node->next = prev;
        prev = Node;
        Node = Next;
    }
    Node = prev;
    //将反转后的链表节点插入到原本的结点当中。    
    ListNode* MoveNode = head;
    ListNode* NNext = Node;
    ListNode* Mnext = head;
    while (Node) {
        Mnext = MoveNode->next;
        NNext = Node->next;
        MoveNode->next = Node;
        Node->next = Mnext;
        MoveNode = Mnext;
        Node = NNext;
    }
}