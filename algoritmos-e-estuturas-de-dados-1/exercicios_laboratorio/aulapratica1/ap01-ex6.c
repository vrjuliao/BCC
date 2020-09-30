#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	printf("Ax^(2) + Bx + C = 0\n");

	printf("\nEntre com o valor de A: ");
	float a;
	scanf("%f", &a);

	printf("Entre com o valor de B: ");
	float b;
	scanf("%f", &b);

	printf("Entre com o valor de C: ");
	float c;
	scanf("%f", &c);

	float delta;
	delta = pow(b,2) - (4*a*c);

	if(delta < 0){
		printf("\nEsta equacao nao possui raizes reais");
	} else if(delta == 0){
		printf("\nEquacao com apenas uma raiz real X = %0.2f", (-b)/(2*a));
	} else {
		float raiz1, raiz2;
		raiz1 = (float)(-b-sqrt(delta))/(2*a);
		raiz2 = (float)(-b+sqrt(delta))/(2*a);
		printf("Raizes da equacao:\nX' = %0.2f  X'' = %0.2f", raiz1, raiz2);
	}
	return 0;
}