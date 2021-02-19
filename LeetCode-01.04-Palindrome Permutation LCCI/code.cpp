class Solution {
public:
    bool canPermutePalindrome(string s) {
        int max = s[0];
        int min = s[0];
        for (int i = 0; i < s.size(); i++) {//先找到最大的和最小的确定要分配数组长度
            if (s[i] > max)
                max = s[i];
            if (s[i] < min)
                min = s[i];
        }
        int size = max - min + 1;//要分配数组长度
        int* arr = new int[size]();//分配数组
        for (int i = 0; i < s.size(); i++) {//计数排序思想，及哈希表
            arr[s[i] - min]++;
        }
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 != 0)//找计数有多少个
                count++;

            if (count > 1)//计数个数大于1返回false
                return false;
        }
        return true;//否则返回true
        delete(arr);//防止内存泄漏
    }
};