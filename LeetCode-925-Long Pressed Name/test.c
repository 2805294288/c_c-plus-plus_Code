//这个题分别对两个数组进行双指针
//1.当字符相同时，让两个字符同时往后走。
//2.当不同时，让typed里面的字符往后走，直到与name里面的字符再次匹配。
bool isLongPressedName(char* name, char* typed) {
    int n = strlen(name);
    int t = strlen(typed);
    int i = 0, j = 0;

    while (j < t) {
        if (i < n && name[i] == typed[j]) {
            i++;
            j++;
        }
        else if (j > 0 && typed[j] == typed[j - 1]) {//让j走到最后，退出循环。
            j++;
        }
        else
            return false;
    }
    if (i == n)//判断name里面的字符是否被遍历完。
        return true;
    else
        return false;
}