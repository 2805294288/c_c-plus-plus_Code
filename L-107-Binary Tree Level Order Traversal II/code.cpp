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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> ret;

        if(root)
        {
            que.push(root);
        }

        while(!que.empty())
        {
            int size = que.size();
            vector<int> tmp;
            for(int i=0; i<size; i++)
            {
                TreeNode* Node = que.front();
                que.pop();
                tmp.push_back(Node->val);

                if(Node->left)
                {
                    que.push(Node->left);
                }
                if(Node->right)
                {
                    que.push(Node->right);
                }
            }
            ret.push_back(tmp);
        }
        reverse(ret.begin(),ret.end());

        return ret;
    }
};







