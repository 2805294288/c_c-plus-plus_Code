/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode == nullptr)
        {
            return nullptr;
        }
        
        if(pNode->right)//如果当前结点有右子树，则当前节点的下一个结点一定是右节点的最左结点
        {
            TreeLinkNode *cur = pNode -> right;
            while(cur->left)
            {
                cur = cur -> left;
            }
            return cur;
        }
        else//如果右子树为空 则肯定是向上找 如果此结点的父节点为空则说明是根节点返回nullptr
        {
            while(pNode->next)
            {//如果父节点不为空则当前结点如果是父节点的左节点 则父节点就是下一个结点（左根右）
                TreeLinkNode *parent = pNode -> next;
                if(pNode == parent -> left)
                {
                    return parent;
                }
                //如果当前节点是父节点的右节点则让父节点从新成为当前结点继续判断
                pNode = pNode -> next;
            }
            return nullptr;
        }
    }
};









