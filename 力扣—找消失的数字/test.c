#include<stdio.h>

int Seek(int* nums, int numsSize)
{
	if (numsSize == 1) {
		if (nums[0] == 0) {
			return 1;
		}
		else
			return 0;
	}
	for (int i = 1; i < numsSize; i++) {
		if (nums[0] < nums[i]) {
			int temp = nums[0];
			nums[0] = nums[i];
			nums[i] = temp;
		}
	}
	int m = nums[0];
	int n = nums[0];
	printf("%d,%d\n", m, n);
	for (int i = 1; i < numsSize; i++) {
		if (nums[1] > nums[i]) {
			int temp = nums[1];
			nums[1] = nums[i];
			nums[i] = temp;
		}
	}
	int min = nums[1];
	printf("%d", min);
	int y=0;
	int p= numsSize;
	while (p&&n>0) {
		n = n - 1;
		y = 0;
		for (int i = 0; i < numsSize; i++) {
			if (n == nums[i]) {
				y = 1;
				break;
			}
			p--;
		}
		if (y == 0) {
			n= 0;
		}
	}
	if (y == 1) {
		if (min == 0) {
			return (m + 1);
		}
		else
			return 0;
	}
	if (y == 0) {
		return n;
	}
}

int main()
{
	int nums[] = {0,1};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int w=Seek(nums, numsSize);
	printf("%d\n", w);
	return 0;
}