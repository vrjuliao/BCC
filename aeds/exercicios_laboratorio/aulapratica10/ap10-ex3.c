#include <stdlib.h>
#include <stdio.h>

void calculaBinario(int x){
	if(x > 1)
		calculaBinario(x/2);
	printf("%d", x%2);
}

int main(int argc, char const *argv[])
{
	int num;
	printf("Digite o numero que deseja imprimir: ");
	scanf("%d", &num);
	if(num < 0){
		printf("Digite um numero positivo\n");
		exit(1);
	}
	calculaBinario(num);
	printf("\n");
	return 0;
}