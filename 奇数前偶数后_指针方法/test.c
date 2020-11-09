#include<stdio.h>

void Sort(int a[], int n)
{
	int b[100] = {0};
	int* q = &a[0];
	int* p = &b[0];
	int m= 0;
	while(m<n){
		if ((*q % 2) != 0) {
			*p++= *q;
		}
		q++;
		m++;
	}
	m = 0;
	q = &a[0];
	while (m < n) {
		if ((*q % 2) == 0) {
			*p++= *q;
		}
		q++;
		m++;
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
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	Sort(a, n);
	return 0;
}
