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
    void GetPath(TreeNode *cur, string path, vector<string>& ret)//这里传的时候不用path引用 而是赋值。ret需要一直传引用来保存。
    {
        path += to_string(cur -> val);//先将当前节点的值转成字符串，在加。
        if(cur -> left == nullptr && cur -> right == nullptr)//当这个节点的左右节点为nullptr的时候则说明到底了返回。
        {
            ret.push_back(path);//并将此次路径进行记录。
            return;
        }
        if (cur -> left)
        {
            GetPath(cur->left, path+"->", ret);//这里传的时候在里面path+"->"这样不会改变当前层的path要不然得删除两次。
        }
        if(cur -> right)
        {
            GetPath(cur->right, path+"->", ret);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret; //最终用来保存路径的字符数组
        string path;//用来记录路径的
        if (root == nullptr)
        {
            return ret;
        }
        GetPath(root,path,ret);
        return ret;
    }
};