// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string str="\0";//定义一个新的字符串
//         for(int i=0;i<s.length();i++){//对字符串s进行遍历
//             if(isalnum(s[i])){//isalnum判定是不是字母或者数字字符
//                 str += tolower(s[i]);//将大写字母转换为小写，如果不是则不动
//             }
//         }
//         string str_rev(str.rbegin(),str.rend());//对新字符串进行反转
//         if(str==str_rev)//如果反转以后的字符串和原字符串相等则返回true
//         return true;
//         else
//         return false;
//     }
// };

//更好的双指针做法。
class Solution {
public:
    bool isPalindrome(string s) {
        string str = "\0";
        int n = s.length();
        int begin = 0;
        int end = n - 1;
        while (begin < end) {
            while (begin < end && (!isalnum(s[begin]))) {
                begin++;//从前往后找符合条件的字符
            }
            while (begin < end && (!isalnum(s[end]))) {
                end--;//从后往前找符合条件的字符
            }
            if (tolower(s[begin]) != tolower(s[end]))
                return false;

            begin++;
            end--;
        }
        return true;
    }
};
