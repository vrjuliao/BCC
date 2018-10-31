#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int vetor[10];

	printf("Digite 10 valores inteiros para o vetor:\n");
	int index;
	for(index = 0; index < 10; index++){
		scanf("%d", &vetor[index]);
	}

	for(index = 0; index < 10; index++){
		printf("Valor %d: %d\n",index+1, vetor[index]);
	}
	return 0;
}