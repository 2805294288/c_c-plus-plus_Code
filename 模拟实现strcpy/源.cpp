#include<stdio.h>
#include<string.h>

void my_strcpy(char *arr_1, char *arr_2)
{
	while (*arr_2!=0) {
		*arr_1++ = *arr_2++;
	}
}

//void my_strcpy(char arr_1[], int a, char arr_2[], int b)
//{
//	for (int i = 0; i < a; i++) {
//		arr_1[i] = 0;
//	}
//	for (int j = 0; j < b; j++) {
//		arr_1[j] = arr_2[j];
//	}
//	for (int i = 0; i < b; i++) {
//		printf("%c", arr_1[i]);
//	}
//}

int main()
{
	char arr_1[100] = { 0 };
	char arr_2[100] = { 0 };
	gets_s(arr_1);
	/*int a = strlen(arr_1);*/
	gets_s(arr_2);
	my_strcpy(arr_1, arr_2);
	printf("%s", arr_1);
}