#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;
	int k = 0;
	for (int j = 0; j < numsSize-1; j++) {
		if (nums[j] != nums[j +1]) {
			nums[k++] = nums[j];
		}
	}
	nums[k++] = nums[numsSize -1];
	return k;
}
int main()
{
	int nums[] = {1};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int k=removeDuplicates(nums, numsSize);
	for (int i = 0; i < k; i++) {
		printf("%d ", nums[i]);
	}
	return 0;
}