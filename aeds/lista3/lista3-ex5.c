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

	switch(sexo){
		case 'h':
		case 'H':
			printf("Peso ideal: %.2f", (72.7 * altura) - 58);
			break;
		case 'm':
		case 'M':
			printf("Peso ideal: %.2f", (62.1 * altura) - 47.7);
			break;
		default:
			printf("ERROR! Caracter inválido!");
			break;
	}
	
	printf("\n");
	return 0;
}