/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //最容易想到的就是暴力法每个进行遍历找比他小的，放到新数组里面。
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* array = (int*)malloc(sizeof(int) * numsSize);
    int count = 0, k = 0;
    for (int i = 0; i < numsSize; i++) {
        count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                count++;
            }
        }
        array[k++] = count;
    }
    return array;
}   