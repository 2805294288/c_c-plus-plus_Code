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


//采用递归的做法，左叶子的定义是当前节点的左叶子不为空，左叶子的左孩子和右孩子为空。采用前序遍历方式。
class Solution {
public:
    void LeftTreeNode(TreeNode *root, int& sum)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->left != nullptr && root->left->left == nullptr && root -> left -> right == nullptr)
        {
            sum += root->left->val;
        }
        if(root->left)
        LeftTreeNode(root->left, sum);
        if(root->right)
        LeftTreeNode(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root == nullptr)
        {
            return sum;
        }
        LeftTreeNode(root,sum);
        return sum;
    }
};