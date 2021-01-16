/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 //递归思想
struct TreeNode* invertTree(struct TreeNode* root) {
    //前序遍历交换
 //    if(root==NULL)
 //    return NULL;
 //    struct TreeNode*temp=root->left;
 //    root->left=root->right;
 //    root->right=temp;
 //    invertTree(root->left);
 //    invertTree(root->right);
 //    return root;



     //后序遍历交换。
     // if(root==NULL)
     // return NULL;

     // struct TreeNode*left=invertTree(root->left);
     // struct TreeNode*right=invertTree(root->right);
     // root->left=right;
     // root->right=left;
     // return root;
}