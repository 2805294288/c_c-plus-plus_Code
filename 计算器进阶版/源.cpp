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
	int (*p[SIZE])(int x,int y) = { NULL,Add,Sub,Mul,Div };
	while (input)
	{
		printf("#################################\n");
		printf("##  1.Add                2.Sub ##\n");
		printf("##  3.Mul      4.Div     5.exit##\n");
		printf("#################################\n");
		printf("Please make a  choose:\n");
		scanf_s("%d", &input);
		if (input < 0 || input>5)
		{
			printf("Please error!");
			continue;
		}
		if (input == 5)
		{
			break;
		}
		printf("Please enter two numbers:\n");
		scanf_s("%d %d", &x, &y);
		ret = (*p[input])(x, y);
		printf("%d\n", ret);
	 }
	return 0;
}