#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf_s("%d %d", &a, &b);
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int m = 0;
	for (int i = 1; i <= b; i++)
	{
		m = a * i;
		if ((m % a == 0) && (m % b == 0))
		{
			printf("%d", m);
			break;
		}
	
	}
	return 0;
}