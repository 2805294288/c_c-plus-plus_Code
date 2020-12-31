/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;

struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* cur = head->next;
    ListNode* sorthead = head;
    sorthead->next = NULL;
    while (cur) {//Í·²å 
        ListNode* next = cur->next;
        if (cur->val <= sorthead->val) {
            cur->next = sorthead;
            sorthead = cur;
        }
        else {
            ListNode* prev = sorthead;
            ListNode* tail = sorthead->next;

            while (tail) {
                if (cur->val <= tail->val) {
                    cur->next = tail;
                    prev->next = cur;
                    break;
                }
                else {
                    prev = tail;
                    tail = tail->next;
                }
            }
            if (tail == NULL) {
                prev->next = cur;
                cur->next = NULL;
            }
        }
        cur = next;
    }
    return sorthead;
}