#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[]){
	printf("Digite o valor do saque:\n");
	int money;
	scanf("%d", &money);

	int divisionRest;
	
	int bills50;
	bills50 = money/50;
	divisionRest = money%50;

	int bills20;
	bills20 = divisionRest/20;
	divisionRest %= 20;

	int bills10;
	bills10 = divisionRest/10;
	divisionRest %= 10;
	
	int bills5;
	bills5 = divisionRest/5;
	divisionRest %= 5;

	int bills2;
	bills2 = divisionRest/2;
	divisionRest %= 2;

	if(bills50){
		printf("%d notas de 50\n", bills50);
	}
	if(bills20){
		printf("%d notas de 20\n", bills20);
	}
	if(bills10){
		printf("%d notas de 10\n", bills10);
	}
	if(bills5){
		printf("%d notas de 5\n", bills5);
	}
	if(bills2){
		printf("%d notas de 2\n", bills2);
	}
	if(divisionRest){
		printf("%d notas de 1\n", divisionRest);
	}

	return 0;
}