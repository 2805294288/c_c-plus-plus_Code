

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize) {
    //先把里面的所有数据^相同为0；相异为1；
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        k = k ^ nums[i];
    }
    //找出最先出现1的地方
    int j = 0;
    for (j = 0; j < 32; j++) {
        if ((1 & k >> j) == 1)
            break;
    }
    int a[10000] = { 0 };
    int b[10000] = { 0 };
    int* array = (int*)malloc(sizeof(int) * 2);
    int m = 0, n = 0;
    //将两个不同的数字分开到两个不同的数组里面。
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] >> j & 1) == 0)
            a[m++] = nums[i];
        else
            b[n++] = nums[i];
    }
    int q = 0, p = 0;
    //分别异或求出两个数字
    for (int i = 0; i < m; i++) {
        q = q ^ a[i];
    }
    for (int i = 0; i < n; i++) {
        p = p ^ b[i];
    }
    *returnSize = 2;
    array[0] = q;
    array[1] = p;
    return array;
}

