class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int size = A.size();

        if(size == 1)//如果size等于1肯定是单调的
        {
            return true;
        }
        int point = 0;

        for(int i=0; i<size-1; i++)//找到前后两个数不相等的位置
            {
                if(A[i] != A[i+1])
                {
                    point = i;
                    break;
                }
            }

        if(A[point]>A[point+1])//起始如果是递减后面保证一直是递减
        {
            for(int i=point; i<size-1; i++)
            {
                if(A[i]<A[i+1])
                {
                    return false;
                }
            }
        }
        else if(A[point]<A[point+1])//初始是递增后面保证一直是递增
        {
            for(int i=point; i<size-1; i++)
            {
                if(A[i]>A[i+1])
                {
                    return false;
                }
            }
        }

        return true;
    }
};