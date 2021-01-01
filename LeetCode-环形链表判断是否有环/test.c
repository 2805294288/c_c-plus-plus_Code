/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode* head) {
    if (head == NULL)
        return false;
    struct ListNode* solw = head;
    struct ListNode* fast = head;
    while (fast && fast->next) {
        solw = solw->next;
        fast = fast->next->next;
        if (solw == fast) {
            return true;
        }
    }
    return false;
}