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
    TreeNode* invertTree(TreeNode* root) {
        //递归法前序遍历进行翻转
        // if(root == nullptr)
        // {
        //     return root;
        // }
        // swap(root->left,root->right);
        // invertTree(root->left);
        // invertTree(root->right);
        // return root;

        //递归法后序遍历进行翻转
        // if(root == nullptr)
        // {
        //     return root;
        // }
        // TreeNode *Left=invertTree(root->left);
        // TreeNode *Right= invertTree(root->right);
        // root->left = Right;
        // root->right = Left;
        // return root;

        //迭代法前序遍历翻转二叉树
        stack<TreeNode*> st;
        if(root)
        {
            st.push(root);
        }
        while(!st.empty())
        {
            TreeNode *Node = st.top();
            st.pop();
            swap(Node->left,Node->right);
            if(Node->right)
            {
                st.push(Node->right);
            }
            if(Node->left)
            {
                st.push(Node->left);
            }
        }
        return root;
    }
};













