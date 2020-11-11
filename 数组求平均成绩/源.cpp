#include<stdio.h>
int  main()
{
	float secore[100];
	int i;
	printf("please enter numbers:\n");
	for (i = 0; i < 10; i++)
		scanf_s("%f", &secore[i]);
	float average(float array[100]);
	float Ave;
	Ave = average(secore);
	printf("average=%f", Ave);
	return 0;
}
float average(float array[100])
{
	int i;
	float aver, sum = array[0];
	for (i = 1; i < 10; i++)
		sum = sum + array[i];
	aver = sum / 10;
	return aver;
}