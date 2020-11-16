#include <stdio.h>
int main()
{
	int arr[100];
	int s = 925;
	int i = 0;
	int n = 0, m = 1;
	char arr_1[15] = { '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while (m > 0) {
		n = s % 16;
		arr[i] = n;
		i++;
		m = s / 16;
		s = m;
	}
		for (i=i-1; i >= 0; i--) {
			int temp = arr[i];
			printf("%c", arr_1[temp-1]);
		}
}