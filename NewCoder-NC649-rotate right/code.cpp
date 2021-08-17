class Solution {
public:
    /**
     * 位移后二进制串的十进制值
     * @param str string字符串 二进制字符串
     * @param k int整型 循环位移次数
     * @return long长整型
     */
    //首先要将字符串进行分割，右移k位就是将倒数第k位到末尾进行切割转移到头部。
    long long rotateRight(string str, int k) {
        int size = str.size();
        k = k % size;//移的数字大于字符串长度取余。
        string tmp = str.substr(size-k,k);
        str = str.substr(0,size-k);
        str = tmp + str;
        
        //二进制转换为十进制做法。
        long long x = 1;
        long long ret = 0;
        for(int i=size-1; i>=0; i--)
        {
            ret += (str[i]-'0')*x;
            x *= 2;
        }
        return ret;
    }
};