#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 3
#define LINES 3

int main(){
	int matrix[LINES][COLUMNS];

	printf("Digite os valores para a matriz %dx%d", LINES, COLUMNS);
	int indexI, indexJ, aux;
	for(indexI = 0; indexI<LINES; indexI++){
		for(indexJ = 0; indexJ<LINES; indexJ++){
			aux = 0;
			prinf("\n[%d][%d]: ", LINES+1, COLUMNS+1);
			scanf("%d", &aux);
			matrix[indexI][indexJ] = aux;
		}
	}
}