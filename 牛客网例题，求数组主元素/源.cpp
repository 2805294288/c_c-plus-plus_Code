#include<stdio.h>

int majorityElement(int* nums, int numsSize)
{
	int  count = 0;
	int q = numsSize / 2;
	for (int i = 0; i <=( numsSize-1)/2 ; i++) {
            count = 0;
		for (int j = i; j <= numsSize-1; j++) {
			if (nums[i] == nums[j])
				count++;
		}
		if (count >q)
			return nums[i];		
	}
	return -1;
}
int main()
{
	int nums[] = { 3,4,3,3};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int p = majorityElement(nums, numsSize);
	printf("%d", p);
	return 0;
}