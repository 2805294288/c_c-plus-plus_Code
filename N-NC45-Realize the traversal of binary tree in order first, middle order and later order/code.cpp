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
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void Front(vector<int>&Fret,TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        Fret.push_back(root->val);
        Front(Fret,root->left);
        Front(Fret,root->right);
    }
    void Mid(vector<int>&Mret,TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        Mid(Mret,root->left);
        Mret.push_back(root->val);
        Mid(Mret,root->right);
    }
    void Tail(vector<int>&Tret,TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        Tail(Tret,root->left);
        Tail(Tret,root->right);
        Tret.push_back(root->val);
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr)
        {
            return ret;
        }
        TreeNode *FNode = root;
        vector<int> Fret;
        Front(Fret,FNode);
        ret.push_back(Fret);
        
        TreeNode *MNode = root;
        vector<int> Mret;
        Mid(Mret,MNode);
        ret.push_back(Mret);
        
        TreeNode *TNode = root;
        vector<int> Tret;
        Tail(Tret,TNode);
        ret.push_back(Tret);
        
        return ret;
    }
};