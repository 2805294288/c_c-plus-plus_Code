/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    
    //将链表拆分到数组里面 然后对数组进行排序，排序按照链表里面的值进行排序。用lambad表达式最后在将各个
    //链表合并起来
    
    ListNode* sortInList(ListNode* head) {
        vector<ListNode*> v1;
        
        ListNode* cur = head;
        while(cur)
        {
            v1.push_back(cur);
            cur = cur ->next;
        }
        
        sort(v1.begin(),v1.end(),[](ListNode* n1, ListNode* n2)->bool
             {
                return n1->val < n2->val;
             });
        
        ListNode* ret = new ListNode(0);
        ListNode* mret = ret;
        for(auto& n:v1)
        {
            mret ->next = n;
            mret = mret ->next;
        }
        mret ->next = nullptr;
        
        ListNode* RET = ret ->next;
        delete ret;
        
        return RET;
    }
};


















