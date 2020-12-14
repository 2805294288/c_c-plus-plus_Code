/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* NewHead = NULL;
    struct ListNode* cur = NULL;
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    else {
        if (l1->val > l2->val) {
            NewHead = l2;
            l2 = l2->next;
        }
        else {
            NewHead = l1;
            l1 = l1->next;
        }
        cur = NewHead;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
            else {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
        }
        if (l1 == NULL)
            cur->next = l2;
        else if (l2 == NULL)
            cur->next = l1;
        return NewHead;
    }
}