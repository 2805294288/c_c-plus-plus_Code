class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @param m int整型 
     * @return int整型
     */
    int ysf(int n, int m) {
    if(n <= 1 || m<=1)
    {
        return -1;
    }
    
    int last = 0;
    for(int i=2; i<=n; i++)
    {
        last = (last + m) % i;
    }
        return last+1;
    }
};