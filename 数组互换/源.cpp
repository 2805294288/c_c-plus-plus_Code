#include<stdio.h>
int main()
{
	int arr_1[] = { 1,2,3,4 };
	int arr_2[] = { 5,6,7,8 };
	printf("before:\n");
	int m = sizeof(arr_1) / sizeof(arr_1[0]);
	printf("arr_1=");
	for (int i = 0; i <= m - 1; i++) {
		printf("%d ", arr_1[i]);
	}
	printf("\n");
	printf("arr_2=");
	for (int i = 0; i <= m - 1; i++) {
		printf("%d ", arr_2[i]);
	}
	printf("\n");
	printf("after:\n");
	for (int i = 0; i <= m - 1; i++) {
		int temp = arr_1[i];
		arr_1[i] = arr_2[i];
		arr_2[i] = temp;
	}
	printf("arr_1=");
	for (int i = 0; i <= m - 1; i++) {
		printf("%d ", arr_1[i]);
	}
	printf("\n");
	printf("arr_2=");
	for (int i = 0; i <= m - 1; i++) {
		printf("%d ", arr_2[i]);
	}
	return 0;
}