/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    //1.链表拷贝
    Node* cur = head;
    while (cur) {
        Node* copy = (Node*)malloc(sizeof(Node));
        copy->val = cur->val;
        copy->next = NULL;
        copy->random = NULL;

        Node* next = cur->next;
        cur->next = copy;
        copy->next = next;

        cur = next;
    }
    //2.处理链表中的random
    cur = head;
    while (cur) {
        Node* next = cur->next->next;
        Node* copy = cur->next;
        copy->next = next;
        if (cur->random != NULL) {
            copy->random = cur->random->next;
        }
        else {
            copy->random = NULL;
        }

        cur = next;
    }
    //3.断开链接   
    cur = head;
    Node* Newhead = cur->next;
    while (cur) {
        Node* copy = cur->next;
        Node* next = cur->next->next;

        if (next != NULL) {
            copy->next = next->next;
        }
        else {
            copy->next = NULL;
        }
        cur = next;
    }
    return Newhead;
}









