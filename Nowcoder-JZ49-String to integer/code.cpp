class Solution {
public:
    int StrToInt(string str) {
        int number = 0;
        int i = 0;
        
        int size = str.size();
        
        if(str[0] == '+' || str[0] == '-')
        {
             i++;
        }
        else if(str[0] <= '0' || str[0] > '9')
        {
            return 0;
        }
        
        while(i<size)
        {
            if(str[i] > '0' && str[i] < '9')
            {
                number = number*10 + (str[i] - '0');
                i++;
            }
            else
            {
                return 0;
            }
        }
        
        if(str[0] == '-')
        {
            return -number;
        }
        else
        {
            return number;
        }
    }
};









