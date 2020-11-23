#include<stdio.h>
#include<assert.h>

const char* my_strstr(const char* str, const char* sub_str)
{
	assert(str);
	assert(sub_str);
	while (*str) {
		const char* p = str;
		const char* q = sub_str;
		while (*p && *q && *p == *q) {
			p++;
			q++;
		}
		if (*q == '\0') {
          return str;
		  break;
		}
		str++;		
	}
}
int main()
{
	const char* str = "abc 123 abc 1234 abcde";
	const char* sub_str = "1234";
	puts(my_strstr(str,sub_str));
}