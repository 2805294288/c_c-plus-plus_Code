/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode* Hcur = head;
    int n = k - 1;
    while (n > 0) {
        Hcur = Hcur->next;
        n--;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (k) {
        fast = fast->next;
        k--;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    int tmp = Hcur->val;
    Hcur->val = slow->val;
    slow->val = tmp;

    return head;
}