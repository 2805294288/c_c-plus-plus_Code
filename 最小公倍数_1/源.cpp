#include<stdio.h>
int main()
{
	int max = 0;
	int min = 0;
	printf("please enter tow number:\n");
	scanf_s("%d %d", &max, &min);
	int mad = max * min;
	if (max < min) {
		int temp = max;
		max = min;
		min = temp;
	}
	//递归法求最大公约数
	while (max % min != 0) {
		int temp = min;
		min = max % min;
		max = min;
	}
	printf("最小公倍数：%d", mad / min);
	return 0;
}