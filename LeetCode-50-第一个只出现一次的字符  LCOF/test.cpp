class Solution {
public:
    char firstUniqChar(string s) {
        char c = 0;
        for (int i = 0; i < s.size(); i++) {
            c = s[i];
            //从第一个字符开始分别从左往右和从右往左寻找第一次出现的位置，如果位置相同，则返回。
            if (s.find(c) == s.rfind(c))
                return c;
        }
        return ' ';
    }
};