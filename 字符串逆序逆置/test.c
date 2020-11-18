#include<stdio.h>
#include<string.h>


int main()
{
	char arr[] = "I like bit.";
	char *arr_1[100] = { 0 };
	char *p=strtok(arr," ");
	arr_1[0] = p;
	int i = 0;
	while(p!=NULL)
	{ 
	 p = strtok(NULL, " ");
	 i++; 
	 arr_1[i] = p;
	}
	 for (int j = i-1; j >= 0; j--) {
		printf("%s ", arr_1[j]);
	}
	return 0;
}