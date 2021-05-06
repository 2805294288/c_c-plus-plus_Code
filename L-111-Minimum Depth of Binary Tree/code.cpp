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
    int minDepth(TreeNode* root) {
        // if(root == nullptr)//递归法，如果结点为空，则返回0；
        // {
        //     return 0;
        // }
        // else if(root->left == nullptr && root -> right != nullptr)//如果左子树为nullptr则返回右子树长度加自身。
        // {
        //     return 1+minDepth(root->right);
        // }
        // else if(root -> right == nullptr && root -> left != nullptr)
        // {
        //     return 1+minDepth(root->left);
        // }
        // return min(minDepth( root->left ),minDepth(root -> right)) + 1;//保证在左右结点都不为空的情况下返回的是左右子树中长度小的。

        //还可以用迭代法，层序遍历的方法只要有一层有一个节点的左右节点都为nullptr，则结束。要不一直往下遍历。
        queue<TreeNode*> que;
        if(root)
        {
            que.push(root);
        }
        int minDepth = 0;
        int state = 0;
        while(!que.empty())
        {
            int size = que.size();
            minDepth++;
            for(int i=0; i<size; i++)
            {
                TreeNode *Node = que.front();
                que.pop();
    
                if(Node -> left == nullptr && Node->right == nullptr)
                {
                    state = 1;
                    break;
                }
                if(Node -> left)
                {
                    que.push(Node -> left);
                }
                if(Node -> right)
                {
                    que.push(Node -> right);
                }
            }
            if(state == 1)
            {
                break;
            }  
        }
        return minDepth;
    }
};















