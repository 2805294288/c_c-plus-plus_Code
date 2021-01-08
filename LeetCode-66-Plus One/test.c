/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* a = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int number = 0, j = 0;
    int n = digitsSize - 1;
    number = digits[n] + 1;
    n = n - 1;
    while (n >= 0) {
        if (number > 9) {
            a[j++] = 0;
            number = digits[n--] + 1;
        }
        else
            break;
    }
    if (n == -1 && number == 10) {
        a[j++] = 0;
    }
    if (number == 10)
        a[j++] = 1;
    else
        a[j++] = number;
    while (n >= 0) {
        a[j++] = digits[n--];
    }
    int m = j - 1, c = j / 2;
    for (int i = 0; i < c; m--, i++) {
        int temp = a[m];
        a[m] = a[i];
        a[i] = temp;
    }
    *returnSize = j;
    return a;
}