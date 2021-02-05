

//既然只有一个那就用异或的办法，先将s里面的异或完，在和t里面的异或。
char findTheDifference(char* s, char* t) {
    int Long_1 = strlen(s);
    int Long_2 = strlen(t);
    int m = 0;
    for (int i = 0; i < Long_1; i++) {
        m = m ^ s[i];
    }
    for (int i = 0; i < Long_2; i++) {
        m = m ^ t[i];
    }
    return m;
}