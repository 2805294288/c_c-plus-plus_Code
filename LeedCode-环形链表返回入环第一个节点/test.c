/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }
    else {
        struct ListNode* meet = slow;
        while (1) {
            if (meet == head)
                break;
            head = head->next;
            meet = meet->next;

        }
        return meet;
    }
    return 0;
}