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
    int maxDepth(TreeNode* root) {
        //递归去做遇到空的时候返回0；否则比较左右树里面层数大的。
        // if(root == nullptr)
        // {
        //     return 0;
        // }
        // return max(maxDepth(root -> left),maxDepth(root -> right))+1;


        //迭代法就是层序遍历的思想。通过层序遍历就可以知道树的层数。
        queue<TreeNode*> que;
        int maxDepth = 0;
        if(root)
        {
            que.push(root);
        }
        while(!que.empty())
        {
            int size = que.size();
            maxDepth++;
            for(int i=0;i<size;i++)
            {
                TreeNode *Node = que.front();
                que.pop();
                if(Node->left)
                {
                    que.push(Node->left);
                }
                if(Node->right)
                {
                    que.push(Node->right);
                }
            } 
        }
        return maxDepth;
    }
};