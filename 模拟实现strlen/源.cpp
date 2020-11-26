#include<stdio.h>

void my_strlen(char* arr)
{
	int count = 0;
	while (*arr != 0) {
		arr++;
		count++;
	}
	printf("%d", count);
}

int main()
{
	char arr[100] = { 0 };
	gets_s(arr);
	my_strlen(arr);
}