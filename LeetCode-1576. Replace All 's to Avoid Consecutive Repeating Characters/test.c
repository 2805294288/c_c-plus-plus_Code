
//C语言的暴力解法，先从头开始找‘？’，当找到‘？’的时候从小写字母a开始往后找和他前后不相同的替换掉。
char* modifyString(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '?') {
            char ch = 'a';
            while ((i > 0 && s[i - 1] == ch) || (s[i] != '\0' && s[i + 1] == ch))
                ch++;

            s[i] = ch;
        }
    }
    return s;
}