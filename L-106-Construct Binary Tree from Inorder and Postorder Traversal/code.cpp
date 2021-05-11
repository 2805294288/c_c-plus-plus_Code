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
    TreeNode* Structure(vector<int>& inorder, vector<int>& postorder)
    {
        //如果后序数组遍历为空则返回空
        if(postorder.size() == 0)
        {
            return nullptr;
        }
        //后序数组最后一个节点是头节点
        int rval = postorder[postorder.size()-1];
        TreeNode* root =new TreeNode(rval);
        //如果此时后续数组只有一个那么返回此root节点
        if(postorder.size() == 1)
        {
            return root;
        }
        //删除后序遍历的最后一个节点
        postorder.pop_back();

        int index = 0;
        for(; index<inorder.size(); index++)
        {
            if(inorder[index] == rval)
            {
                break;
            }
        }
        //分割中序数组
        vector<int> leftinorder(inorder.begin(), inorder.begin()+index);
        vector<int> rightinorder(inorder.begin()+index+1, inorder.end());
        
        //分割后序数组
        vector<int> leftpostorder(postorder.begin(), postorder.begin()+leftinorder.size());
        vector<int> rightpostorder(postorder.begin()+leftinorder.size(), postorder.end());

        root->left=Structure(leftinorder,leftpostorder);
        root->right=Structure(rightinorder,rightpostorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0)
        {
            return nullptr;
        }
        return Structure(inorder, postorder);
    }
};