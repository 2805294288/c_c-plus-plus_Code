/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        queue<Node*> que;
        if(root != nullptr)
        {
            que.push(root);
        }
        while(!que.empty())
        {
            int size=que.size();
            vector<int> tmp;
            for(int i=0; i<size; i++)
            {
                Node* Tnode = que.front();
                que.pop();
                tmp.push_back(Tnode->val);
                for(int j=0;j<Tnode->children.size();j++)//Node类的内部结构是用vector来保存children个数，二叉树是只有左右孩子，所以左二叉树的时候只需要判断左右孩子为不为空。N叉树的话判断里面有几个孩子，将孩子全部保存在队列之中，并判断孩子为不为空，空则不保存。
                {
                    if(Tnode->children[j])
                    que.push(Tnode->children[j]);
                }
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};





























