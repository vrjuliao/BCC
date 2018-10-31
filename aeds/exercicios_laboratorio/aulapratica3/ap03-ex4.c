#include <stdio.h>
#include <stdlib.h>

int MDC(int num1, int num2){
	int rest;
	while(num2 != 0){
		rest = num1%num2;
		num1 = num2;
		num2 = rest;
	}
	int resultadoMDC;
	resultadoMDC = num1;
	return resultadoMDC;
}

int main (int argc, char *argv[]){
	int num1, num2;
	char c;
	
	do{
		printf("Digite dois numeros:\n");
		scanf("%d %d%*c", &num1, &num2);

		int resultado = MDC(num1, num2);
		printf("MDC: %d\n", resultado);

		printf("Continua? (S/N) ");
		c = getchar();
		printf("\n");
	}while ((c == 'S') || (c == 's'));
	
	return 0;
}