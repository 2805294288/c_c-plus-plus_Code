//判断一个数组是否是二叉树的后序遍历
//二叉搜索树性质 根的左边比根小根的右边比根大
//由于是后序遍历 左右根的遍历顺序
//数组最后一个则是root（根）。
//则从左到最右不包括根先找到比根大的第一个位置。则说明这个位置之前的都应该是根的左边比根小。
//则只需要判断从此位置往后是否都比根大。不满足则返回false。
//然后判断这个根的左边和右边是否也满足这个条件。递归去做。

class Solution {
public:
    bool Judge(vector<int>& sequence, int L, int R)
    {
        if(L >= R)
        {
            return true;
        }
        
        int i = L;
        for(; i < R; i++)
        {
            if(sequence[i] > sequence[R])
            {
                break;
            }
        }
        
        for(int j = i; j < R; j++)
        {
            if(sequence[j] < sequence[R])
            {
                return false;
            }
        }
        
        return Judge(sequence, L, i-1) && Judge(sequence, i, R-1);
    }
    
    bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.size() == 0)
    {
        return false;
    }

    return Judge(sequence, 0, sequence.size()-1);
    }
};