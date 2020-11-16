#include<stdio.h>

#define ROW 4
#define COL 4

int Lookup(int a[ROW][COL], int num)
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (a[i][j] == num)
				return 1;
		}
	}
	return 0;
}

int main()
{
	int a[ROW][COL] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int i = 0;
	int j = 0;
	int num;
	printf("数组为:\n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	printf("Please Enter:");
	scanf_s("%d", &num);
	int r = Lookup(a, num);
	if (r == 1)
	{
		printf("存在\n");
	}
	else if (r == 0)
		printf("不存在\n");
	return 0;

}