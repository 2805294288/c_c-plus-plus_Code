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

 //层序遍历迭代法。
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while(cur != nullptr || !st.empty())
        {
            if(cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;//左
            }
            else
            {
                cur = st.top();
                st.pop();

                ret.push_back(cur->val);//中
                cur = cur->right;//右
            }
        }
        return ret;
    }
};


















