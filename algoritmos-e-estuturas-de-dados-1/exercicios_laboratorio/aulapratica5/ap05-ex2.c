#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	float vetor[7];

	printf("Digite 10 valores para o vetor:\n");
	int index;
	for(index = 0; index < 7; index++){
		scanf("%f", &vetor[index]);
	}

	for(index = 0; index < 7; index++){
		printf("Valor %d: %f\n",index+1, vetor[index]);
	}

	printf("\nNumeros pares de indice do vetor digitados:\n");
	for(index = 0; index < 7; index+=2){
		printf("Valor do indice %d: %f\n",index, vetor[index]);
	}
	return 0;
}