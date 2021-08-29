class Solution {
public:
    bool isPerfectSquare(int num) {
        long long num1 = num;
        long maxnum = 0;
        long long ch1 = 0;
        while(num1)
        {
            maxnum = num1;
            num1 /= 2;
            ch1 = num1 * num1;
            if(ch1 <= num)
            {
                break;
            } 
        }
        long long ch2 = 0;
        while(num1 <= maxnum)
        {
            ch2 = num1 * num1;
            if(ch2 == num)
            {
                return true;
            }
            num1++;
        }

        return false;
    }
};