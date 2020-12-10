/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        if (A == NULL) {
            return false;
        }
        else if (A->next == NULL) {
            return true;
        }
        else if (A->next->next == NULL) {
            struct ListNode* SecondNumber = A->next;
            if (A->val != SecondNumber->val)
                return false;
            else
                return true;
        }
        else {
            struct ListNode* slow = A, * fast = A;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;

            }
            struct ListNode* SecondA = NULL;
            if (fast == NULL)
                SecondA = slow;
            else
                SecondA = slow->next;
            struct ListNode* p, * pre = NULL;
            struct ListNode* cur = SecondA;
            while (cur) {
                p = cur->next;
                cur->next = pre;
                pre = cur;
                cur = p;
            }
            SecondA = pre;
            while (SecondA->next) {
                if (A->val != SecondA->val) {
                    return false;
                }
                A = A->next;
                SecondA = SecondA->next;
            }
            return true;
        }
    }
};