#include<stdio.h>
#include<assert.h>

char* My_strncpy(char* dest, const char* src, size_t n)
{
    assert(dest);
    assert(src);

    char* ret = dest;
    while (n--)
    {
        *dest++ = *src++;
    }
    return ret;
}

int main()
{
    char dest[] = "1234566667676";
    char src[] = "abcd";
    My_strncpy(dest, src, 7);
    printf("%s", dest);
}