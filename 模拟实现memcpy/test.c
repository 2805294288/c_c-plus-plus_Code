#include<stdio.h>
#include<assert.h>

void* my_memcpy(void* b, const void* a, int num)
{
	assert(b);
	assert(a);
	char* p = (char*)b;
	char* q = (const char*)a;
	while (num) {
		*p++ = *q++;
		num--;
	}
	return b;
}

int main()
{
	int a[] = { 1,2,3,4,5,6 };
	int b[10] = { 0 };
	my_memcpy(b, a, sizeof(a));
	for (int i = 0; i < 10; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}