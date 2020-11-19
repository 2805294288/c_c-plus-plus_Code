#include<stdio.h>
int main()
{
	float  sum = 1;
	for (int i = 1; i <= 1000; i++) {
		float n = 2*i;
		float n_1 = n / (n - 1);
		float n_2 = n / (n + 1);
		sum = sum * (n_1 * n_2);
	}
	printf("%f", sum);
}