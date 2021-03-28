class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        int num1 = 0;
        int num2 = 0;
        int next = 0;
        int sum = 0;
        int Ssize = s.size()-1;
        int Tsize = t.size()-1;
        string ret;
        
        while(Ssize>=0 || Tsize>=0)
        {
            num1 = 0;
            num2 = 0;
            
            if(Ssize >= 0)
            {
                num1 = s[Ssize]-'0';
            }
            if(Tsize >= 0)
            {
                num2 = t[Tsize]-'0';
            }
            
            sum = num1 + num2 + next;
            if(sum >= 10)
            {
                sum = sum - 10;
                next = 1;
            }
            else
            {
                sum = sum;
                next = 0;
            }
            
            ret += sum + '0';
            Ssize--;
            Tsize--;
        }
        
        if(next == 1)
        {
            ret += '1';
        }
        
        reverse(ret.begin(),ret.end());
        
        return ret;
    }
};















