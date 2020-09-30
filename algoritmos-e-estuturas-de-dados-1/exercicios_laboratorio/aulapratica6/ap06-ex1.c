#include <stdio.h>
#include <stdlib.h>

#define MAX_Linhas 12
#define MAX_Colunas 12

int **createMatrix(int lines, int columns){

	int **matrix;
	int indexI, indexJ;
	matrix = (int**) calloc(lines, sizeof(int*));

// for (temp = 0; temp < 4; temp++ )
// int matrix[lines][columns], indexI, indexJ;
	for(indexI = 0; indexI<lines; indexI++){
		*(matrix + indexI) = (int*) calloc(columns,sizeof(int));
		for(indexJ = 0; indexJ<columns; indexJ++){
			matrix[indexI][indexJ] = 1;
		}
	}
	return matrix;
}

int **sumMatrix(int **matrix1, int **matrix2, int lines, int columns){
	int **resultMatrix;
	int indexI, indexJ;
	resultMatrix = (int**)calloc(lines, sizeof(int*));
	
	for(indexI = 0; indexI<lines; indexI++){
		*(resultMatrix + indexI) = (int*)calloc(columns,sizeof(int));
		for(indexJ = 0; indexJ<columns; indexJ++){
			resultMatrix[indexI][indexJ] = matrix1[indexI][indexJ] + matrix2[indexI][indexJ];
		}
	}
	return resultMatrix;
}

void printMatrix(int **matrix, int lines, int columns){
	int indexI, indexJ;
	for(indexI = 0; indexI<lines; indexI++){
		for(indexJ = 0; indexJ<columns; indexJ++){
			printf("\nElemento[%d][%d]: %d", indexI, indexJ, matrix[indexI][indexJ]);
		}
	}
	printf("\n");
}

int main(int argc, const char *argv[]){	
	int lines, columns;

	//solicitando do usuario as linhas e colunas da matriz
	printf("Numero de linhas:");
	scanf("%d", &lines);

	printf("\nNumero de colunas:");
	scanf("%d", &columns);
	

	if(columns > MAX_Colunas || lines > MAX_Linhas){
		printf("\nERRO! \nNumero maximo de linhas: %d\nNumero maximo de colunas: %d\n", MAX_Linhas, MAX_Colunas);
		return 0;

	} else if (columns < 1 || lines < 1){
		printf("\nERRO!\nDigite um numero maior que zero");
		return 0;
	}

	//criando as matrizes
	int **matrix1, **matrix2, **resultMatrix;
	matrix1 = createMatrix(lines, columns);
	matrix2 = createMatrix(lines, columns);
	resultMatrix = sumMatrix(matrix1, matrix2, lines, columns);
	printMatrix(resultMatrix, lines, columns);
	return 0;
}