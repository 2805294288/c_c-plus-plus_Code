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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> que;
        int ret = 0;
        if (root)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            int size = que.size();
            for (int i=0; i<size; i++)
            {
                TreeNode* Node = que.front();
                que.pop();
                if(i == 0)
                {
                    ret = Node -> val;
                }
                if(Node -> left)
                que.push(Node->left);
                if(Node -> right)
                que.push(Node->right);
            }
        }
        return ret;
    }
};