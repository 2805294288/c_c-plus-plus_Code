int compress(char* chars, int charsSize)
{
    int count = 0;
    int i, j;
    for (i = 0, j = 0; j < charsSize; i = j) {
        while (j < charsSize && chars[j] == chars[i]) {
            j++;
        }

        chars[count++] = chars[i];
        int times = j - i;
        if (times == 1) {
            continue;
        }

        if (times >= 10) {
            chars[count++] = times / 10 + '0';
            chars[count++] = times % 10 + '0';
        }
        else {
            chars[count++] = times + '0';
        }
    }

    return count;
}