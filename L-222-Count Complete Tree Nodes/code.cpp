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
    //迭代法
    // void countNode(int& count,TreeNode* root)
    // {
    //     if(root == nullptr)
    //     {
    //         return;
    //     }
    //     countNode(count,root->left);
    //     countNode(count,root->right);
    //     count++;
    // }
    int countNodes(TreeNode* root) {
    //     int count = 0;
    //     if(root == nullptr)
    //     {
    //         return 0;
    //     }
    //     countNode(count,root);
    //     return count;
    // }


    // if(root == nullptr)
    // {
    //     return 0;
    // }
    // return countNodes(root->left)+countNodes(root->right)+1;
    // }

    //层序遍历迭代法
        queue<TreeNode*> que;
        int count = 0;
        if(root)
        {
            que.push(root);
        }
        while(!que.empty())
        {
            TreeNode *Node = que.front();
            que.pop();
            count++;
            if(Node->left)
            {
                que.push(Node->left);
            }
            if(Node -> right)
            {
                que.push(Node->right);
            }
        }
        return count;
    }
};











