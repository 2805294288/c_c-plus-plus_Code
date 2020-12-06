#include<stdio.h>

void addToArrayForm(int* A, int ASize,int k) {
	int number = 0;
	int T = 1;
	int j = 0;
	while(ASize>0){
		ASize--;
		T = 1  ;
	for (int i = 0; i < ASize; i++) {
		T = T * 10;
	 }
	number = number + (A[j++] * T);
    }
	/*printf("%d\n", number);*/
	int number_1 =number + k;
	int n = 0, i = 0;
	int number_2 = 0;
	while (number_1 > 0) {
	    number_2 = number_1 % 10;
		number_1 = number_1 / 10;
		A[i++] = number_2;	
		n = i;
	}
	/*for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");*/
	int start = 0, end = n-1;
	while(start<end){
		int temp=A[start];
		A[start] = A[end];
		A[end] = temp;
		start++;
		end--;
	}
	//for (int i = 0; i < n; i++) {
	//	printf("%d ", A[i]);
	//}
}

int main()
{
	int  A[] = { 9,9,9,9,9,9,9,9,9};
	int ASize = sizeof(A) / sizeof(A[0]);
	int k = 1;
	addToArrayForm(A, ASize,k);
}