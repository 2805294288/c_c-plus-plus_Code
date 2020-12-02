#include<stdio.h>
#include<string.h>
int main()
{
	char arr[100] = { 0 };
	gets(arr);
	int n = 0;
	int m=strlen(arr);
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		arr[m] = arr[i];
		m++;         
	}
	for (int i = n; i < m; i++) {
		printf("%c", arr[i]);
	}
	return 0;
}


