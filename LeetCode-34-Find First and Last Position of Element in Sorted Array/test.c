/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* a = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    a[0] = a[1] = -1;
    if (numsSize == 0) {
        return a;
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            a[0] = i;
            break;
        }
    }
    for (int j = numsSize - 1; j >= 0; j--) {
        if (nums[j] == target) {
            a[1] = j;
            break;
        }
    }
    return a;
}