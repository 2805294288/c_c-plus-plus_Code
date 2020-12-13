/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode类
  * @param k int整型
  * @return ListNode类
  */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    struct ListNode* slow = pListHead;
    struct ListNode* fast = pListHead;
    while (k) {
        if (fast == NULL)
            return NULL;
        fast = fast->next;
        k--;
    }
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}