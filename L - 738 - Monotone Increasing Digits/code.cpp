class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string number = to_string(n);//将数字改为字符串字符串可以下标访问操作
        int idx = number.size();//记录从后往前最前面那个不满足条件的
        for(int i = number.size()-1; i > 0; i--)
        {
            if(number[i] < number[i-1])
            {
                idx = i;//idx记录的是最前不满足条件的
                number[i-1]--;
            }
        }

        for(int j = idx; j < number.size(); j++)//从idex之前一个减减，从idx之后的都改为9
        {
            number[j] = '9';//这里是字符9
        }

        return stoi(number);
    }
};