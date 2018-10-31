#include <stdio.h>
#include <stdlib.h>

int negativos(int n, int vet[]){
	int index, qtdNegativos;
	qtdNegativos = 0;
	for(index = 0; index < n; index++){
		if(vet[index] < 0) qtdNegativos++;
	}
	return qtdNegativos;
}