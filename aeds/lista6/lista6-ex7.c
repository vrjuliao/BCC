#include <stdio.h>
#include <stdlib.h>

int somatorios(int n, int v[], int w[]){
	w[0] = v[0];
	int index;
	for (index = 1; index < n; index++){
		w[index] = v[index] + w[index-1];
	}
	return 1;
}