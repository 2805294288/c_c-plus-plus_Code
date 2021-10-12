class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int reverse(int x) {
        int number = 0;
        int state = 1;
        int ret = 0;
        
        if(x < 0)
        {
            x = x * -1;
            state = -1;
        }
        
        while(x)
        {
            ret = ret*10 + x % 10;
            x = x / 10;
            
        }
        
        if(state == -1)
        {
            ret = ret * -1;
        }
        
        if(ret < INT_MIN || ret > INT_MAX)
        {
            return 0;
        }
        else
            return ret;
    }
};