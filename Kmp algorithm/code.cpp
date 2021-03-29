class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算模板串S在文本串T中出现了多少次
     * @param S string字符串 模板串
     * @param T string字符串 文本串
     * @return int整型
     */
    int kmp(string S, string T) {
       // write code here
        int count = 0;
        int it = 0;
        int i = 0;
        while(i<T.size()-S.size()-1)
        {
            it = T.find(S,i);
            if(it!=string::npos)
            {
                count++;
                i=it+1;
            }
            if(it==string::npos)
            {
                break;
            }
            
        }
        return count;
    }
};