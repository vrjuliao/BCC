#include <stdio.h>
#include <stdlib.h>

int maiores(int n, int vet[], int x){
	int index, qtdMaiores;
	qtdMaiores = 0;
	for(index = 0; index < n; index++){
		if(vet[index] > x) qtdMaiores++;
	}
	return qtdMaiores;
}