#include<stdio.h>
int main() {
	int money = 3;    

	int drink = 0;    

	int dronk = 0;     

	int num_bot = 0;  

	drink = money;   

	while (drink > 0) {     
		dronk += drink;     
		num_bot += drink;
		drink = num_bot / 2;
		num_bot %= 2;
	}
	printf("%d\n", dronk);
	return 0;
}