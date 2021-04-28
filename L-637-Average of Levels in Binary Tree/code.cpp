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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        queue<TreeNode*> que;

        if(root)
        {
            que.push(root);
        }
        while(!que.empty())
        {
            double sum = 0;
            int size = que.size();
            for(int i=0; i< size; i++)
            {
                TreeNode *Node = que.front();
                que.pop();

                sum += Node->val;
                if(Node->left)
                {
                    que.push(Node->left);
                }
                if(Node->right)
                {
                    que.push(Node->right);
                }
            }

            ret.push_back(sum / size);
        }

        return ret;
    }
};





