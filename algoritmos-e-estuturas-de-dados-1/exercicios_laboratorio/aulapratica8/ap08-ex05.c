#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct pessoa{
	char nome [50];
	int idade;
	float peso;
	float altura;
} individuo;

int main(int argc, char const *argv[]){
	individuo vetorCadastro[MAX];
	int numIndividuos;

	printf("Numero de cadastros: ");
	scanf("%d", &numIndividuos);
	if(numIndividuos > 10){
		printf("o limite de individuos e 10;");
		exit(1);
	}


	int index;
	for(index = 0; index < numIndividuos; index++){
		__fpurge(stdin);
		printf("Nome: ");
		fgets(vetorCadastro[index].nome, 51, stdin);
		__fpurge(stdin);

		printf("Idade: ");
		scanf("%d", &vetorCadastro[index].idade);
		printf("Peso: ");
		scanf("%f", &vetorCadastro[index].peso);
		printf("Altura: ");
		scanf("%f", &vetorCadastro[index].altura);
		printf("\n");
	}

	
	printf("Imprimindo dados\n");
	for(index = 0; index < numIndividuos; index++){
		printf("Nome: %s\n", vetorCadastro[index].nome);
		printf("Idade: %d\n", vetorCadastro[index].idade);
		printf("Peso: %0.2f\n", vetorCadastro[index].peso);
		printf("Altura: %0.2f", vetorCadastro[index].altura);
		printf("\n");
	}

	return 0;
}