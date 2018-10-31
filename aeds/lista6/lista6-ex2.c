#include <stdio.h>
#include <stdlib.h>

void imprimeDecrescente(int num1, int num2, int num3){
	int numeros[3] = {num1, num2, num3};
	// numeros = {num1, num2, num3};

	int indexI;
	int aux;
	int indexJ;
	for(indexI=0; indexI < 3; indexI++){
		for(indexJ = indexI+1; indexJ < 3; indexJ++){
			if(numeros[indexI] > numeros[indexJ]){
				aux = numeros[indexI];
				numeros[indexI] = numeros[indexJ];
				numeros[indexJ] = aux;
			}
		}
	}

	for(indexI = 2; indexI >= 0; indexI--){
		printf("%d ", numeros[indexI]);
	}
	printf("\n");

}

int main(int argc, char *argv[]){
	int num1, num2, num3;

	printf("Digite 3 numeros: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	imprimeDecrescente(num1, num2, num3);
	return 0;
}