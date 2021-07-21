class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    //求平方根，实际是为了考察二分法。
    
    //但是在计算的时候不要用mid * mid会溢出 用mid = x / mid
    //当相同时则直接返回
    //不相同时则去两边找
    int sqrt(int x) {
        if(x <= 1)
        {
            return x;
        }
        int head = 1;
        int tail = x;
        while(head <= tail)
        {
            int mid = (head + tail) / 2;
            if(mid == x / mid)
            {
                return mid;
            }
            else
            {
                if(mid < x / mid)
                {
                    head = mid + 1;
                }
                else
                {
                    tail = mid - 1;
                }
            }
        }
        return tail;
    }
};