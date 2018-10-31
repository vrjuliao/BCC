#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("Digite sua altura em mentros: ");
	float altura;
	scanf("%f", &altura);
	if(altura<=0){
		printf("ERROR! Altura inválida!\n");
		return 0;
	}

	printf("\nDigite o sexo\n");
	printf("h/H para homens - m/M para mulheres: ");
	char sexo;
	scanf(" %c", &sexo);

	if(sexo == 'h' || sexo == 'H')
		printf("Peso ideal: %.2f", (72.7 * altura) - 58);
	else if(sexo == 'm' || sexo == 'M')
		printf("Peso ideal: %.2f", (62.1 * altura) - 47.7);
	else 
		printf("ERROR! Caracter inválido!");

	printf("\n");

	return 0;
}