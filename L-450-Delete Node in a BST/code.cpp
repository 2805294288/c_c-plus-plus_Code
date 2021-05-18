/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)//如果给的是一颗空树则直接返回nullptr
        {
            return nullptr;
        }
        TreeNode *parent = root; //记录前一个结点
        TreeNode *cur = root;//root作为树的根返回值不可以更改 用cur代替
        while(cur)
        {
            if(cur->val < key)//去右边找
            {
                parent = cur;
                cur=cur->right;
            }
            else if(cur->val > key)//去左边找
            {
                parent = cur;
                cur=cur->left;
            }
            else//找到了要删除的结点
            {
                //找到以后主要分两种情况
                //1.左右孩子有一个为空
                //2.左右孩子都不为空
                if(cur->left == nullptr)//如果找到的结点左为空
                {
                    if(cur==root)//左为空的前提下 如果要删除的为root结点 则更新root结点
                    {
                        root = cur -> right;
                    } 
                    else //如果不是root结点则判断该节点为parent结点的左右，并让其指向当前结点的右边
                    {
                        if(parent -> left == cur)
                        {
                            parent -> left = cur->right;
                        }
                        else
                            parent -> right = cur -> right;
                    }
                    delete cur;//删除找到的结点并返回根节点
                    return root;
                }
                else if(cur->right == nullptr)
                {
                    if(cur==root)//右为空的前提下 如果要删除的为root结点 则更新root结点
                    {
                        root = cur -> left;
                    }
                    else //如果不是root结点则判断该节点为parent结点的左右，并让其指向当前结点的左边
                    {
                        if(parent -> right == cur)
                        {
                            parent -> right = cur->left;
                        }
                        else
                            parent -> left = cur -> left;
                    } 
                    delete cur;//删除找到的结点并返回根节点
                    return root;
                }
                else
                {
                    //左右孩子都不为空 则寻找当前结点往下的左子树的最右结点或者右子树的最左结点
                    TreeNode *_parent = cur;
                    TreeNode *_cur = cur->right;//到右数去找最左结点
                    while(_cur->left)//如果当前节点的左节点为空则结束，我就是当前最左结点。不可以用_cur，用_cur会让最左结点为空，下面操作会越界问题
                    {
                        _parent = _cur;
                        _cur=_cur->left;
                    }

                    cur->val = _cur->val;//将找到的值进行替换
                    if(_parent->right == _cur)//既然是最左结点则该结点的左节点为空。看当前结点位于parent结点的左右
                    {
                        _parent -> right = _cur->right;
                    }
                    else
                    {
                        _parent->left = _cur -> right;
                    }
                    delete _cur;//删除找到的结点
                } 
                return root;//返回root
            }
        }
        return root;
    }
};



