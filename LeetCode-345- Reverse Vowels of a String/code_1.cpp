//利用双指针
//一个从头开始遍历
//一个从后开始遍历
//当前后都是元音字母时开始交换。

class Solution {
public:
    string reverseVowels(string s) {
        int head = 0;
        int tail = s.length()-1;
        string str = "aeiou";

        while(head<tail)
        {//前遍历
            while(head<tail && str.find(tolower(s[head]))==-1)
            {
                head++;
            }//后遍历
            while(head<tail  && str.find(tolower(s[tail]))==-1)
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