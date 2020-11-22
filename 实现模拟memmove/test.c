#include<stdio.h>
#include<assert.h>
#include<string.h>

void* my_memmove(void* b, void* a, int num)
{
	assert(b);
	assert(a);
	char* p = (char*)b;
	char* q = (char*)a;
	if (q < p && p < q + num) {
		q = q + num - 1;
		p = p + num - 1;
		while (num) {
			*p-- = *q--;
			num--;
		}
	}
	else
	while (num) {
		*p++ = *q++;
		num--;
	}
	return b;
}

int main()
{
	/*int a[] = { 1,2,3,4,5,6 };
	int b[10] = { 0 };*/
	char str[10] = "abcde123";
	my_memmove(str + 1, str, strlen(str) + 1);
		/*for (int i = 0; i < 10; i++) {
			printf("%d ", b[i]);
		}*/
		printf("%s", str);
	return 0;
} 