/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;

        Node *Head = new Node(0);
        Head -> next = nullptr;
        Node *Hcur = Head;

        Node *cur = head;
        while(cur)
        {
            Node *node = new Node(cur -> val);
            m[cur] = node;
            Hcur -> next = node;
            Hcur = Hcur -> next;
            cur = cur -> next;
        }

        cur = head;
        while(cur)
        {
            m[cur] -> random = m[cur -> random];
            cur = cur -> next;
        }

        return Head -> next;
    }
};



















