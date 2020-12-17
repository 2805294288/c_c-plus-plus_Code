/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* Onetail = (ListNode*)malloc(sizeof(ListNode));
        ListNode* Twotail = (ListNode*)malloc(sizeof(ListNode));
        ListNode* OneHead = Onetail;
        ListNode* Twohead = Twotail;
        while (pHead) {
            if (pHead->val < x) {
                Onetail->next = pHead;
                Onetail = Onetail->next;
                pHead = pHead->next;
            }
            else {
                Twotail->next = pHead;
                Twotail = Twotail->next;
                pHead = pHead->next;
            }
        }
        Twotail->next = NULL;
        Onetail->next = Twohead->next;
        return OneHead->next;
    }
};