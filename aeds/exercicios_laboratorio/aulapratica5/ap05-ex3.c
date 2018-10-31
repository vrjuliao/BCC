#include <stdlib.h>
#include <stdio.h>

#define MAX 100

int main(int argc, char *argv[]){
	int maxIndex;

	printf("Digite o valor de elementos do vetor (0-100):\n");
	scanf("%d", &maxIndex);

	if(maxIndex > 100) {
		printf("Valor inválido de elementos para o vetor\n");
		return 0;
	}
	int vetor[maxIndex];
	printf("Digite todos os valores para o vetor:\n");
	int index;
	for(index = 0; index < maxIndex; index++){
		scanf("%d", &vetor[index]);
	}

	for(index = maxIndex - 1; index >= 0; index--){
		printf("Valor %d: %d\n",index+1, vetor[index]);
	}

	return 0;
}