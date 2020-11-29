#include <stdio.h>
#include <assert.h>
#include <string.h>

char* MyStrncat(char* dest, char* src, size_t len)
{
	assert(NULL != dest && NULL != src);
	char* ret = dest;
	int offset = 0;
	while (*dest)
	{
		*dest++;
	}
	while (len--)
	{
		*dest++ = *src++;
	}

	*dest = '\0'; //strncat总是在结果后面添加'\0'，而不是用'\0'填充目标剩余空间

	return ret;
}

int main()
{
	char arr1[6] = "World";
	char arr2[15] = "Hello ";
	printf("%s\n", MyStrncat(arr2, arr1, strlen(arr2)));
	return 0;
}
