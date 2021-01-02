//杨辉三角
#include<stdio.h>
int main()
{
	int a[10][10], i, j;
	int n = 0;
	scanf_s("%d", &n);
	//要输出的行数
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++) 
		{
			if (i == j || j == 0)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	return 0;

}