#include<stdio.h>

void Sort(int a[],int n)
{
	int b[100] = { 0 };
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			b[j] = a[i];
			j++;
		}
	}
	for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0) {
				b[j] = a[i];
				j++;
			}
	}
		for (int j = 0; j < n; j++) {
			printf("%d ", b[j]);
		}
}

int main()
{
	int n = 0;
	int a[100];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++){
		scanf_s("%d", &a[i]);
	}
	Sort(a,n);
	return 0;
}
