#include<stdio.h>
#include<string.h>

void Merge(char a[], char b[], int n)
{
	char* q = a;
	char* p = b;
	int m = 0;
	while (*q != '\0')
		q++;
	while (m <= n) {
		*q++ = *p++;
		m++;
	}
	puts(a);
}

int main()
{
	char a[100] = { 0 };
	char b[100] = { 0 };
	gets(a);
	gets(b);
	int n = strlen(b);
	Merge(a, b, n);
}