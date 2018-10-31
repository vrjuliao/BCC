#include <stdlib.h>
#include <stdio.h>

#define LIN 3
#define COL 3

int **alloc_matrix(){
	int index;
	int **matrix;
	matrix = (int **) calloc(LIN, sizeof(int *));
	if(matrix==0 || matrix == NULL){
		printf("ERRO! \nMemoria indisponível\n");
		exit(1);
	}

	for(index = 0; index < LIN; index++){
		*(matrix+index) = (int *) calloc(COL, sizeof(int));
		if(*(matrix+index)==0 || *(matrix+index) == NULL){
			printf("ERRO! \nMemoria indisponível\n");
			exit(1);
		}
	}
	return matrix;
}

void free_matrix(int **matrix){
	int index;
	for(index = 0; index < LIN; index++)
		free(*(matrix+index));
	free(matrix);
}

void input_matrix_data(int **matrix){
	int indexI, indexJ, aux;
	for(indexI = 0; indexI < LIN; indexI++){
		for(indexJ = 0; indexJ < COL; indexJ++){
			printf("Elemento[%d][%d]: ",indexI, indexJ);
			scanf("%d", &aux);
			matrix[indexI][indexJ] = aux;
		}
	}
}

float diagonal_average(int **matrix){
	int index;
	float sum;
	sum = 0.0;
	for(index = 0; index < LIN; index++){
		sum += matrix[index][index];
	}
	return sum/((float) LIN);
}

int main(){
	int **matrix;
	matrix = alloc_matrix();
	input_matrix_data(matrix);
	float diagonalAverage;
	diagonalAverage = diagonal_average(matrix);
	printf("\nMédia da diagonal: %f\n", diagonalAverage);
	return 0;
}