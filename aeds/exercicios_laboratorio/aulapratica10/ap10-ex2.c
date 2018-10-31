#include <stdlib.h>
#include <stdio.h>


void serieAckerman(int termoInicial){
	printf("%d\n", termoInicial);
	if(termoInicial != 1){
		if(termoInicial%2 == 0){
			serieAckerman(termoInicial/2);
		} else {
			serieAckerman((termoInicial*3) + 1);
		}
	}
}

int main(int argc, char const *argv[])
{
	int termoInicial;
	printf("Termo inicial: ");
	scanf("%d", &termoInicial);

	if(termoInicial <= 0){
		printf("Digite um numero maior que zero\n");
		exit(1);
	}

	serieAckerman(termoInicial);
	return 0;
}