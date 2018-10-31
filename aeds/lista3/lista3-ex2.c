#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("Digite um numero inteiro:  ");
	int value;
	scanf("%d", &value);

	if(value > 0){
		if(value%2){
			printf("Valor impar");
		} else {
			printf("Valor par");
		}
	} else {
		printf("ERROR! 	O VALOR DEVE MAIOR OU IGUAL A ZERO!");
	}
	printf("\n");
	return 0;
}