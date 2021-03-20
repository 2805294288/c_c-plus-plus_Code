class Solution {
public:

    string addStrings(string num1, string num2) {
        int num1_end = num1.size()-1;
        int num2_end = num2.size()-1;
        int number1 = 0;
        int number2 = 0;
        string ret;
        int sum = 0;
        int next = 0;

        while(num1_end>=0 || num2_end>=0)
        {
            number1 = 0;
            number2 = 0;
            if(num1_end >=0)
            {
                number1 = num1[num1_end] - '0';
                num1_end--;
            }
            if(num2_end >= 0)
            {
                number2 = num2[num2_end] - '0';
                num2_end--;
            }

            sum = number1 + number2 + next;
            if(sum >= 10)
            {
                ret += (sum-10) + '0';
                next = 1;
            }
            else
            {
                ret += sum + '0';
                next = 0;
            }
        }

        if(next == 1)
        {
            ret += '1';
        }

        reverse(ret.begin(),ret.end());

        return ret;
    }
};