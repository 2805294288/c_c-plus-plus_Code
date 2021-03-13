//利用双指针
//一个从头开始遍历
//一个从后开始遍历
//当前后都是元音字母时开始交换。

class Solution {
public:
    string reverseVowels(string s) {
        int head = 0;
        int tail = s.length()-1;

        while(head<tail)
        {//前遍历
            while(head<tail  && tolower(s[head]) != 'a' && tolower(s[head]) != 'e' && tolower(s[head]) != 'i' && tolower(s[head]) != 'o' && tolower(s[head]) != 'u')
            {
                head++;
            }//后遍历
            while(head<tail  && tolower(s[tail]) != 'a' && tolower(s[tail]) != 'e' && tolower(s[tail]) != 'i' && tolower(s[tail]) != 'o' && tolower(s[tail]) != 'u')
            {
                tail--;
            }
            //交换
            swap(s[head],s[tail]);
            head++;
            tail--;
        }
        return s;
    }
};