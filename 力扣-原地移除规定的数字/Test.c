#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
	int t = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] !=val) {
			nums[t++] = nums[i];
		}
	}
	return t;
}
int main()
{
	int nums[] = { 3,4,5,6,3 };
	int numsSize_1 = sizeof(nums) / sizeof(nums[0]);
	int t=removeElement(nums,numsSize_1,3);
	for (int i = 0; i < t; i++) {
		printf("%d ", nums[i]);
	} 
	return 0;
}