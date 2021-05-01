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

 //迭代法，利用前序遍历，中左右，改变为中右左，在一反转。左右中即可。
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;

        if(root)
        {
            st.push(root);
        }

        while(!st.empty())
        {
            TreeNode* Node = st.top();
            st.pop();
            ret.push_back(Node->val);//处理中值。

            if(Node->left)//后处理左，则先入左。
            {
                st.push(Node->left);
            }
            if(Node->right)//先处理右，则后入右。
            {
                st.push(Node->right);
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};



















