#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("Digite a idade do nadador: ");
	int age;
	scanf("%d", &age);

	if(age >= 5){
		printf("Categoria ");
		if(age >= 5 && age <= 7)
			printf("infantil A");
		else if (age >= 8 && age <= 10)
			printf("infantil B");
		else if (age >= 11 && age <= 13)
			printf("juvenil A");
		else if (age >= 14 && age <= 17)
			printf("juvenil B");
		else if (age >= 18)
			printf("Sênior");
	} else {
		printf("ERROR! VALOR INVÁLIDO!");
	}

	printf("\n");
	return 0;
}