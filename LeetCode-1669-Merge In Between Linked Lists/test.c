/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    ListNode* L1head = list1;
    ListNode* L1tail = list1;
    a = a - 1;
    //找到要删除第一个节点的前一个
    while (a--) {
        L1head = L1head->next;
    }
    ListNode* Rhead = L1head->next;
    b = b + 1;
    //找到删除到那个结点的后一个。
    while (b--) {
        L1tail = L1tail->next;
    }
    //释放掉中间的结点
    ListNode* next = Rhead->next;
    while (Rhead != L1tail && next != NULL) {
        free(Rhead);
        Rhead = next;
        next = next->next;
    }
    //对链表进行合并。
    ListNode* L2tail = list2;
    while (L2tail->next) {
        L2tail = L2tail->next;
    }
    L1head->next = list2;
    L2tail->next = L1tail;

    return list1;
}






