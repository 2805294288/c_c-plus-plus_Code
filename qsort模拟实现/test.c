#include<stdio.h>
#include<assert.h>

int CompInt(const void* _xp, const void* _yp)
{
	int* xp = (int*)_xp;
	int* yp = (int*)_yp;

	if (*xp > * yp) {
		return 1;
	}
	else if (*xp < *yp) {
		return -1;
	}
	else {
		return 0;
	}
}

void Print(int* arr, int num)
{
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap(char* src, char* dst, int size)
{
	while (size) {
		char temp = *src;
		*src = *dst;
		*dst = temp;
		size--;
		src++, dst++;
	}
}

void my_qsort(void* arr, int num, int size, int(*comp)(const void*, const void*))
{
	assert(arr != NULL);
	assert(comp != NULL);

	char* e = (char*)arr;

	for (int i = 0; i < num - 1; i++) {
		int flag = 0;
		for (int j = 0; j < num - 1 - i; j++) {
			if (comp(e + j * size, e + (j + 1) * size) > 0) {
				flag = 1;
				swap(e + j * size, e + (j + 1) * size, size);
			}
		}

		if (flag == 0) {
			break;
		}
	}
}

int main()
{

	int arr[] = { 24, 345, 1, 4, 6 };
	int num = sizeof(arr) / sizeof(arr[0]);
	Print(arr, num);
	my_qsort(arr, num, sizeof(int), CompInt);
	Print(arr, num);

	system("pause");
	return 0;
}