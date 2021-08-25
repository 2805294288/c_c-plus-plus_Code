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
    bool Judge(TreeNode* root, int sum, int& targetSum)
    {
        if(root == nullptr)
        {
            return false;
        }
        sum += root -> val;
        if(root -> left == nullptr && root -> right == nullptr && sum == targetSum)
        {
            return true;
        }

        return Judge(root->left, sum, targetSum) || Judge(root->right, sum, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
        {
            return false;
        }
        int sum = 0;
        return Judge(root, sum, targetSum);
    }
};