#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raizes(double a, double b, double c, double *raiz1, double *raiz2){
	double delta;
	int qtdRaizes;
	delta = (b*b) - (4*a*c);
	if(delta == 0){
		qtdRaizes = 1;
		*raiz1 = (b*(-1))/(2*a);
	} else if (delta < 0){
		qtdRaizes = 0;
	} else {
		qtdRaizes = 2;
		*raiz1 = (b*(-1) - sqrt(delta))/(2*a);
		*raiz2 = (b*(-1) + sqrt(delta))/(2*a);
	}

	return qtdRaizes;
}

int main(int argc, char *argv){
	double a, b, c, raiz1, raiz2;
	printf("ax² + bx + c = 0\n");	
	printf("Entre com o valor para A: ");
	scanf("%lf", &a);
	printf("Entre com o valor para B: ");
	scanf("%lf", &b);
	printf("Entre com o valor para C: ");
	scanf("%lf", &c);

	int qtdRaizes;
	qtdRaizes = raizes(a, b, c, &raiz1, &raiz2);
	if(qtdRaizes == 0){
		printf("Nao existe solucao Real para equacao.");
	} else if(qtdRaizes == 1){
		printf("Unica raiz da equacao: %lf", raiz1);
	} else {
		printf("Raizes da equacao: %lf, %lf", raiz1, raiz2);
	}
	printf("\n");
	return 0;
}