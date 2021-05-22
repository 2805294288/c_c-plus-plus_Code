/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool Find(TreeNode* root, TreeNode* x)//先写一个寻找函数，判断X节点在不在这个树里面
    {
        if(root == nullptr)
        {
            return false;
        }
        else if(root == x)
        {
            return true;
        }

        return Find(root -> left, x) || Find(root -> right, x);//递归着在这个树的左子树和右子树中去找
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if(p == root || q == root)//当里面有一个结点等于root结点时说明另外一个结点肯定在当前结点之下。如示例二这种情况。
        {
            return root;
        }

        bool pleft,pright,qleft,qright;
        pleft = Find(root -> left,p);//判断p结点在当前树的左边还是右边
        pright = !pleft;

        qleft = Find(root -> left,q);//判断q结点在当前树的左边还是右边
        qright = !qleft;

        if(pleft && qright || pright && qleft) //如果结点在当前结点的一左一右则当前结点就是最近公共祖先。
            return root;
        else if(qleft && pleft) //如果都在左边则在左边去找最近公共祖先
            return lowestCommonAncestor(root -> left, p, q);
        else    //如果都在右边则在右边去找最近公共祖先
            return lowestCommonAncestor(root -> right, p, q);
    }
};