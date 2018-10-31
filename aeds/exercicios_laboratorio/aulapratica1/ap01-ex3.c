#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	int catetoA, catetoB, hipotenusaC;
	//valores do terno pitagórico
	catetoA = 3;
	catetoB = 4;
	hipotenusaC = 5;

	//desenhando o triangulo
	printf(" |\\\n%d| \\%d\n |__\\\n  %d\n", catetoB, hipotenusaC, catetoA);

	float semiPerimetro;
	semiPerimetro=(float)(catetoA+catetoB+hipotenusaC)/2;

	float area;
	area = sqrt(semiPerimetro*(semiPerimetro-catetoA)*(semiPerimetro-catetoB)*(semiPerimetro-hipotenusaC));

	printf("A area do triangulo = %0.2f\n", area);

	return 0;
}