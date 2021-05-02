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
    int maxDepth(Node* root) {
        //层序遍历迭代法求解
        queue<Node*> que;
        if(root)
        {
            que.push(root);
        }
        int maxDepth = 0;
        while(!que.empty())
        {
            int size = que.size();
            maxDepth++;
            for(int i=0;i<size;i++)
            {
                Node *node = que.front();
                que.pop();
                for(int j=0;j<node->children.size();j++)
                {
                    if(node->children[j])
                    que.push(node->children[j]);
                }
            }
        }
        return maxDepth;
    }
};