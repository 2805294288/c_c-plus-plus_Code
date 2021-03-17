/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getDecimalValue(struct ListNode* head){
    int size = 0;
    int res = 0;
    struct ListNode* cur = head;

    while(cur)
    {
        size++;
        cur = cur->next;
    }

    while(head)
    {
        if(head->val==1)
        {
            res += pow(2,size-1);
            size--;
        }
        else
        {
            size--;
        }

        head = head->next;
    }

    return res;
}