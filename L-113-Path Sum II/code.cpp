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
    void TreePath(TreeNode* root, vector<int> path, int sum, vector<vector<int>>& ret, int& targetSum)
    {
        if(root == nullptr)
        {
            return;
        }
        sum += root -> val;
        path.push_back(root->val);
        if(root -> left == nullptr && root -> right == nullptr && sum == targetSum)
        {
            ret.push_back(path);
            return;
        }
        if(root->left)
        TreePath(root->left, path, sum, ret, targetSum);
        if(root->right)
        TreePath(root->right, path, sum, ret, targetSum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        if(root == nullptr)
        {
            return ret;
        }
        vector<int> path;
        int sum = 0;
        TreePath(root, path, sum, ret, targetSum);
        return ret;
    }
};