/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    int ksize = 0;
    int knum = K;
    while (knum) {
        ksize++;
        knum = knum / 10;
    }

    int len = ASize > ksize ? ASize : ksize;
    int* retArr = (int*)malloc(sizeof(int) * (len + 1));

    int Ai = ASize - 1;
    int reti = 0;
    int nextNum = 0;
    while (len--) {
        int a = 0;
        if (Ai >= 0) {
            a = A[Ai];
            Ai--;
        }
        int ret = a + K % 10 + nextNum;
        K = K / 10;
        if (ret > 9) {
            ret = ret - 10;
            nextNum = 1;
        }
        else {
            nextNum = 0;
        }
        retArr[reti] = ret;
        reti++;
    }
    if (nextNum == 1) {
        retArr[reti] = 1;
        reti++;
    }
    int start = 0;
    int end = reti - 1;
    while (start < end) {
        int temp = retArr[start];
        retArr[start] = retArr[end];
        retArr[end] = temp;
        start++;
        end--;
    }
    *returnSize = reti;
    return retArr;
}