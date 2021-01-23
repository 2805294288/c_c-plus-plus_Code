/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //先将原数组平方以后放到新数组里面，再对新数组进行排序，排序方法自行选择。
 //  int compare(const void*a,const void*b)
 // {
 //     return *(int*)a-*(int*)b;
 // }
 //int* sortedSquares(int* nums, int numsSize, int* returnSize){
     // int *a=(int *)malloc(sizeof(int)*numsSize);
     // for(int i=0;i<numsSize;i++){
     //     a[i]=pow(nums[i],2);
     // }
     // qsort(a,numsSize,sizeof(int),compare);
     // * returnSize=numsSize;
     // return a;
 //}
 //既然是有序的则考虑用双指针的归并排序的做法。遍历一遍。
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int end = numsSize - 1;
    int front = 0;
    int k = numsSize - 1;
    int* a = (int*)malloc(sizeof(int) * numsSize);
    //当头指针和尾指针相遇时原数组遍历完毕，并且在新数组从后往前放较大的哪一个。
    while (front <= end) {
        if (pow(nums[front], 2) > pow(nums[end], 2)) {
            a[k--] = pow(nums[front], 2);
            front++;
        }
        else {
            a[k--] = pow(nums[end], 2);
            end--;
        }
    }
    *returnSize = numsSize;
    return a;
}












