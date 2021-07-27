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
    TreeNode *Build(vector<int> & preorder, int InL, int InR, int PeL, int PeR)
    {
        if(PeL > PeR)
        return nullptr;

        TreeNode *root = new TreeNode(preorder[PeL]);
        int index = m[preorder[PeL]];

        root -> left = Build(preorder, InL, index - 1, PeL + 1, index - InL + PeL);
        root -> right = Build(preorder, index + 1, InR, index -InL + PeL + 1, PeR);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0)
        {
            return nullptr;
        }

        for(int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }

        return Build(preorder, 0, inorder.size() - 1, 0, preorder.size() -1);
    }
private:
    unordered_map<int,int> m;
};