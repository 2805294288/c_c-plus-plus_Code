#include <stdio.h>

int Num(int i)
{
	int count = 0;
	while (i > 0) {
		count++;
		i /= 10;
	}
	return count;
}

int Is_shuixianhua(int i, int num)
{
	int sum = 0;
	int j = 0;
	int m = i;
	int n = 1;
	while (m > 0) {
		int temp = m % 10;
		m /= 10;
		for (j = num; j > 0; j--) {
			n *= temp;
		}
		sum += n;
		n = 1;
	}
	if (sum == i) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	int i = 0;
	for (i = 0; i < 100000; i++) {
		int num = Num(i);
		if (Is_shuixianhua(i, num)) {
			printf("%d\n", i);
		}
	}
	return 0;
}