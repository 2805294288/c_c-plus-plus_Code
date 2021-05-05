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
    //迭代法求解
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> Nodest;
        stack<string> Pathst;
        vector<string> ret;
        if(root == nullptr)
        {
            return ret;
        }
        Nodest.push(root);
        Pathst.push(to_string(root->val));
        while(!Nodest.empty())
        {
            TreeNode *node = Nodest.top();
            Nodest.pop();
            string path = Pathst.top();
            Pathst.pop();

            if(node -> left == nullptr && node -> right == nullptr)
            {
                ret.push_back(path);
            }
            if(node -> right)
            {
                Nodest.push(node->right);
                Pathst.push(path + "->" + to_string(node -> right -> val));
            }
            if(node -> left)
            {
                Nodest.push(node->left);
                Pathst.push(path + "->" + to_string(node -> left -> val));
            }
        }
        return ret;
    }
};