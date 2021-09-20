/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int Func(TreeNode* root, int& MaxSum)
    {
        if(root == nullptr)
        {
            return 0;
        }
        
        int Left = max(Func(root->left,MaxSum),0);
        int Right = max(Func(root->right,MaxSum),0);
        
        int sum = root->val + Left + Right;
        MaxSum = max(MaxSum, sum);
        
        return root->val + max(Left,Right);
    }
    
    int maxPathSum(TreeNode* root) {
        int MaxSum = INT_MIN;
        Func(root,MaxSum);
        return MaxSum;
    }
};















