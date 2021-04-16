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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ret;
        if(root == nullptr)
        {
            return ret;
        }
        st.push(root);
        while(!st.empty())
        {
            TreeNode *Node = st.top();
            st.pop();
            ret.push_back(Node->val);
            if(Node->right)
            st.push(Node->right);
            if(Node->left)
            st.push(Node->left);
        }

        return ret;
    }
};