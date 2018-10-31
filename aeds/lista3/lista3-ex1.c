#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("Digite um numero para A\n");
	float valorA;
	scanf("%f", &valorA);

	printf("Digite um numero para B\n");
	float valorB;
	scanf("%f", &valorB);

	if(valorA > valorB)
		printf("A é maior que B");
	else if (valorA < valorB)
		printf("B é maior que A");
	else 
		printf("A é igual B");

	printf("\n");

	return 0;
}