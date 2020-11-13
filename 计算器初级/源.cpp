#include<stdio.h>

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
#define SIZE 5
int main()
{
	int x, y;
	int input = 1;
	int ret = 0;
	while (input)
	{
		printf("#################################\n");
		printf("##  1.Add                2.Sub ##\n");
		printf("##  3.Mul      4.Div     5.exit##\n");
		printf("#################################\n");
		printf("Please make a  choose:\n");
		scanf_s("%d", &input);
		if (input == 5)
		{
			break;
		}
		switch (input)
		{
		case 1:
			printf("Please enter two numbers:\n");
			scanf_s("%d %d", &x, &y);
			ret = Add(x, y);
			printf("结果为：%d\n", ret);
			continue;
		case 2:
			printf("Please enter two numbers:\n");
			scanf_s("%d %d", &x, &y);
			ret = Sub(x, y);
			printf("结果为：%d\n", ret);
			continue;
		case 3:
			printf("Please enter two numbers:\n");
			scanf_s("%d %d", &x, &y);
			ret = Mul(x, y);
			printf("结果为：%d\n", ret);
			continue;
		case 4:
			printf("Please enter two numbers:\n");
			scanf_s("%d %d", &x, &y);
			ret = Div(x, y);
			printf("结果为：%d\n", ret);
			continue;
		default:
			printf("Enter error!!!");
			continue;
		}
		return 0;
	}
}