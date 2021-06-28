/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool Judge(TreeNode* p1,TreeNode* p2)
    {
        if(p1 != nullptr && p2 == nullptr)
        {
            return true;
        }
        else if(p1 == nullptr && p2 != nullptr)
        {
            return false;
        }
        else if(p1 == nullptr && p2 == nullptr)
        {
            return true;
        }
        
        if(p1 -> val != p2 -> val)
            return false;
        
        return Judge(p1 -> left, p2 -> left) && Judge(p1 -> right, p2 -> right);
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    
    if(pRoot1 == nullptr || pRoot2 == nullptr)
    {
        return false;
    }
        
    TreeNode *p1 = pRoot1;
    TreeNode *p2 = pRoot2;

    if(p1 -> val == p2 -> val)
    {
        if(Judge(p1,p2))
        {
            return true;
        }
    }

    if(HasSubtree(p1 -> left, p2) || HasSubtree(p1 -> right, p2))
    {
        return true;
    }
        
    return false;
    }
};





