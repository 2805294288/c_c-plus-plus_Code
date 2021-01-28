char* compressString(char* S) {
    int Long = strlen(S);//先求原字符串的长度
    if (Long <= 2)//如果小于等于2，则不会被压缩
        return S;
    int i = 0;
    char* a = (char*)malloc(sizeof(char) * 2 * Long);//申请要返回的空间
    int j = 0;
    a[j] = S[i];//将第一个给申请好的数组
    int number = 1;
    //将整个数组遍历
    while (S[i] != '\0') {
        number = 0;
        while (S[i] != '\0' && a[j] == S[i])
        {
            i++;
            number++;
        }
        int number_1 = number;
        int count = 0;
        while (number > 0) {
            number = number / 10;
            count++;
        }
        int count2 = j + count;
        int count3 = count2;
        while (count > 0) {
            a[count2--] = number_1 % 10 + '0';
            number_1 /= 10;
            count--;
        }
        j = count3;
        a[++j] = S[i];
    }
    a[++j] = '\0';
    //判断是否被压缩了
    if (Long <= j - 1)
        return S;
    else
        return a;
}