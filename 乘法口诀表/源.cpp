#include<stdio.h>
int main()
{
    for (int j = 1; j <= 9; j++) {
        for (int i = 1; i <= 9; i++) {
            printf("%d*%d=%d  ", i, j, i * j);
            if (i == j) {
                break;
            }
        }
        printf("\n");
    }
    return 0;
}