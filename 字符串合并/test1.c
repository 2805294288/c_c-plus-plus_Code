//#include<stdio.h>
//#include<string.h>
//
//void  Merge(char a[], char b[],int a_1,int a_2)
//{
//	    int i = a_1;
//		int j = 0;
//		for ( j = 0; j < a_2; j++) {
//			a[i + j] = b[j];
//		}
//	      a[i + j] = 0;
//	      puts(a);
//}
//
//int main()
//{
//	char a[50] = { 0 };
//	char b[20] = { 0 };
//	gets_s(a);
//	int a_1=strlen(a);
//	gets_s(b);
//	int a_2 = strlen(b);
//	Merge(a, b,a_1,a_2);
//	puts(a);
//}

#include<stdio.h>
#include<string.h>

void  merge(char a[], char b[],int a_2)
{
	char* q = a;
	char* p = b;
	int m = 0;
	while (*q != '\0')
		q++;
	while (m <= a_2) {
		*q++ = *p++;
		m++;
	}
	puts(a);
}

int main()
{
	char a[500] = { 0 };
	char b[200] = { 0 };
	gets(a);
	gets(b);
	int a_2 = strlen(b);
	merge(a, b,a_2);
}