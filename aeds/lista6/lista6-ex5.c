#include <stdio.h>
#include <stdlib.h>

int pares(int n, int vet[]){
	int index, qtdPares;
	qtdPares = 0;
	for(index = 0; index < n; index++){
		if(vet[index]%2 == 0) qtdPares++;
	}
	return qtdPares;
}