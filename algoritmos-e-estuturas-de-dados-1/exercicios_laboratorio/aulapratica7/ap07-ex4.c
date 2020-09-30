#include <stdlib.h>
#include <stdio.h>

void inputMatrixDimensions(char matrixName, int *lines, int *columns){
	printf("=== Matriz %c ===", matrixName);
	printf("\nNumero de linhas: ");
	scanf("%d", lines);

	printf("Numero de colunas: ");
	scanf("%d", columns);
	printf("\n");
}

float **createMatrix(int lines, int columns){
	float **matrix;
	int index;
	matrix = (float **) calloc(lines, sizeof(float *));
	if(matrix==0 || matrix == NULL){
		printf("ERRO! \nMemoria indisponível\n");
		exit(1);
	}

	for(index = 0; index < lines; index++){
		*(matrix+index) = (float *) calloc(columns, sizeof(float));
		if(*(matrix+index)==0 || *(matrix+index) == NULL){
			printf("ERRO! \nMemoria indisponível\n");
			exit(1);
		}
	}
	return matrix;
}

void inputMatrixData(char matrixName, float **matrix, int lines, int columns){
	printf("\n=== Matriz %c ===\n", matrixName);
	int indexI, indexJ;
	float aux;
	for(indexI = 0; indexI < lines; indexI++){
		for(indexJ = 0; indexJ < columns; indexJ++){
			printf("Elemento[%d][%d]: ",indexI, indexJ);
			scanf("%f", &aux);
			matrix[indexI][indexJ] = aux;
		}
	}
}

void multiplyMatrix(int linesA, int columnsA, int columnsB, float **resultMatrix,float **matrixA, float **matrixB){
	int indexJ, indexI, indexK, aux;
	for(indexI = 0; indexI<linesA; indexI++){
		for(indexJ = 0; indexJ<columnsB; indexJ++){
			aux = 0;
			for(indexK = 0; indexK<columnsA; indexK++){
				aux+=matrixA[indexI][indexK]*matrixB[indexK][indexJ];
			}
			resultMatrix[indexI][indexJ] = aux;
		}
	}
}

void annulMatrix(int lines, int columns, float **matrix){
	int indexJ, indexI;
	for(indexI = 0; indexI<lines; indexI++){
		for(indexJ = 0; indexJ<columns; indexJ++){
			matrix[indexI][indexJ] = 0;
		}
	}
}

void printMatrix(int lines, int columns, float **matrix){
	int indexI, indexJ;
	for(indexI = 0; indexI<lines; indexI++){
		for(indexJ = 0; indexJ<columns; indexJ++){
			printf("\nElemento[%d][%d]: %0.3f", indexI, indexJ, matrix[indexI][indexJ]);
		}
	}
	printf("\n");
}

void freeMatrix(int lines, float **matrix){
	int index;
	for(index = 0; index < lines; index++)
		free(*(matrix+index));
	free(matrix);
}

int main(int argc, const char *argv[]){	
	int linesA, columnsA, linesB, columnsB;
	float **matrixA, **matrixB, **matrixResult;

	//solicitando do usuario as linhas e colunas da matriz A
	inputMatrixDimensions('A', &linesA, &columnsA);
	//solicitando do usuario as linhas e colunas da matriz B
	inputMatrixDimensions('B', &linesB, &columnsB);

	if(linesA <= 0 || columnsA <= 0 || linesB <= 0 || columnsB <= 0) {
		printf("\nErro! Digite um numero maior que zero para a quatidade de linhas e colunas.\n");
		return 0;
	} else if(columnsA != linesB){
		printf("\nErro! O numero de linhas e colunas de A e B devem ser iguais.\n");
		return 0;
	}
	
	matrixA = createMatrix(linesA, columnsA);
	matrixB = createMatrix(linesB, columnsB);
	matrixResult = createMatrix(linesA, columnsB);
	annulMatrix(linesA, columnsB, matrixResult);

	inputMatrixData('A', matrixA, linesA, columnsA);
	inputMatrixData('B', matrixB, linesB, columnsB);
	multiplyMatrix(linesA, columnsA, columnsB, matrixResult, matrixA, matrixB);
	printMatrix(linesA, columnsB, matrixResult);
	
	freeMatrix(linesA, matrixResult);
	freeMatrix(linesA, matrixA);
	freeMatrix(linesB, matrixB);

	return 0;
}