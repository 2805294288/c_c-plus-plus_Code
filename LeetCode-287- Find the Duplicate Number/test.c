//第一个思路，先对数组进行排序（qsort），从前往后遍历，有相同的则返回。

// int compare(const void*a,const void*b)
// {
//     return *(int*)a-*(int*)b;
// }
// int findDuplicate(int* nums, int numsSize){
//     qsort(nums,numsSize,sizeof(int),compare);
//     for(int i=0;i<numsSize-1;i++){
//         if(nums[i]==nums[i+1])
//         return nums[i];
//     }
//     return 0;
// }

//利用希尔排序 时间复杂度o(nlongn)-o（n^2) 不稳定。
// void ShellSost(int *nums,int numsSize)
// {
//     int end=0;
//     int gap=numsSize;
//     int number=0;
//     while(gap>1){
//         gap=gap/3+1;
//         for(int i=0;i<numsSize-gap;i++){
//             end=i;
//             number=nums[end+gap];
//             while(end>=0){
//                 if(number<nums[end]){
//                     nums[end+gap]=nums[end];
//                     end -= gap;
//                 }
//                 else
//                 break;
//             }
//             nums[end+gap]=number;
//         }
//     }
// }
// int findDuplicate(int* nums, int numsSize){
//     ShellSost(nums,numsSize);
//     for(int i=0;i<numsSize-1;i++){
//         if(nums[i]==nums[i+1])
//         return nums[i];
//     }
//     return 0;
// }

//采用计数排序排序的思路，即哈希表。
//时间复杂度o（2n），空间复杂度o（numsSize）；
int findDuplicate(int* nums, int numsSize) {
    int* a = (int*)malloc(sizeof(int) * numsSize);
    memset(a, 0, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        a[nums[i]] = a[nums[i]] + 1;
    }
    int j = 0;
    for (j = 0; j < numsSize; j++) {
        if (a[j] >= 2) {
            break;
        }
    }
    return j;
    free(a);
}



















