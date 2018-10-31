#include <stdlib.h>
#include <stdio.h>


void printProgressaoGeometrica(int numElementos, float termoInicial, float razao){
	if(numElementos > 0){
		printf("%f\n", termoInicial);
		numElementos--;
		printProgressaoGeometrica(numElementos, termoInicial*razao, razao);
	}
}

int main(int argc, char const *argv[])
{
	float termoInicial, razao;
	int numElementos;	
	printf("Termo inicial: ");
	scanf("%f", &termoInicial);

	__fpurge(stdin);
	printf("Razao: ");
	scanf("%f", &razao);

	__fpurge(stdin);
	printf("Numero de elementos: ");
	scanf("%d", &numElementos);

	printProgressaoGeometrica(numElementos, termoInicial, razao);
	return 0;
}