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
    //o(n)的做法用空间换时间 用栈操作
    bool Find(TreeNode *root, TreeNode* p, stack<TreeNode*>& path)
    {
        if(root == nullptr)//当前结点为空则返回false说明没找到
        {
            return false;
        }

        path.push(root);//先将当前结点入进去
        if(root == p)//如果找到了那个结点则返回不用找了
        {
            return true;
        }

        if(Find(root -> left, p, path))//先去递归的左边去找，如果左边找到则不让用在找
            return true;
        if(Find(root -> right, p, path))//左边没找到递归的右边去找，如果右边找到则不让用在找
            return true;

        path.pop();//如果当前节点的左右都没找到则将当前结点出栈，返回上一层再去找。记得返回false才会继续往下找。
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> ppath;
        stack<TreeNode*> qpath;

        Find(root,p,ppath);
        Find(root,q,qpath);
        //让栈里面的个数相等，然后比较栈顶元素是否相同。相同的时候出。
        while(ppath.size() > qpath.size())
        {
            ppath.pop();
        }
        while(ppath.size() < qpath.size())
        {
            qpath.pop();
        }

        while(ppath.top() != qpath.top())
        {
            ppath.pop();
            qpath.pop();
        }

        return ppath.top();
    }
};