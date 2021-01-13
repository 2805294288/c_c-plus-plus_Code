/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    assert(head);
    if (head->next == NULL)
        return NULL;
    ListNode* slow = head;
    ListNode* sfast = head;
    ListNode* prev = head;
    while (n--) {
        sfast = sfast->next;
    }
    while (sfast) {
        prev = slow;
        slow = slow->next;
        sfast = sfast->next;
    }
    if (slow->next == NULL) {
        prev->next = NULL;
        free(slow);
    }
    else {
        ListNode* Node = slow->next;
        slow->val = Node->val;
        slow->next = Node->next;
        free(Node);
    }
    return head;
}