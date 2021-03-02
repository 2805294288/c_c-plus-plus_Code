class Solution {
public:
    bool detectCapitalUse(string word) {
        int size = word.length();
        int Big = 0;//大写字符
        int Small = 0;//小写字符
        for (int i = 0; i < size; i++)//先遍历字符串中的字符
        {
            if (islower(word[i]))//islower（）小写字符个数
            {
                Small++;
            }
            else if (isupper(word[i]))//isupper（）大写字符个数
            {
                Big++;
            }
        }
        if (Small == size || Big == size)//如果都是大写或者小写返回true
        {
            return true;
        }
        else if (Big == 1 && isupper(word[0]))//如果大写只有一个且是第一个返回true
        {
            return true;
        }
        else
            return false;
    }
};