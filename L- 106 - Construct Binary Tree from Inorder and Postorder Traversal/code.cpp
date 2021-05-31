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
    TreeNode *Build(vector<int> &postorder, int InL,int InR, int PtL, int PtR)
    {
        if(PtL > PtR)
        return nullptr;

        TreeNode *root = new TreeNode(postorder[PtR]);

        int index = m[postorder[PtR]];
        root -> left = Build(postorder, InL, index-1, PtL, index - InL + PtL - 1);
        root -> right = Build(postorder, index + 1, InR, index - InL + PtL, PtR - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0)
        {
            return nullptr;
        }
       
        for(int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }

        return Build(postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
private:
    unordered_map<int,int> m;
};