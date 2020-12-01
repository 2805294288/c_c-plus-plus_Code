#include<stdio.h>

int main()
{
	int arr[] = { 1,2,3,2,3,4 };
	int sum = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sum; i++) {
		int n = 1;
		for (int j = 0; j < sum ; j++) {
			if (arr[i] == arr[j])
				n++;
		}
		if (n == 2) {
			printf("%d ", arr[i]);
		}
	}
	return 0;
}