#include<stdio.h>

int Binsearch(int arry[], int num, int trget)
{
	int strat = 0;
	int end = num - 1;
	while (strat <= end) {
		int mid = (strat + end) / 2;
		if (trget < arry[mid])
			end = mid - 1;
		else if (trget > arry[mid])
			strat = mid + 1;
		else
			return mid;
	}

	return -1;
}


int main()
{
	int trget = 8;
	int arry[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sum = sizeof(arry) / sizeof(0);//在main函数中求数组长度！！！
	int index = Binsearch(arry, sum, trget);
	printf("%d", index);
}