#include <stdio.h>
#include <stdlib.h>

#define linhasA 2
#define colunasA 3
#define linhasB 3
#define colunasB 3

void inputMatrixData(char matrixName, int lines, int columns, float matrix[lines][columns]){
	float aux;
	int i, j;
	for(i=0; i < lines; i++) {
		for(j=0; j < columns; j++) {
			printf("Digite o valor %c[%d][%d] para a matriz %c:\n", matrixName, i+1, j+1, matrixName);
			scanf("%f", &aux);
			matrix[i][j] = aux;
		}
	}
}

void annulMatrix(int lines, int columns, float matrix[lines][columns]){
	int indexJ, indexI;
	for(indexI = 0; indexI<lines; indexI++){
		for(indexJ = 0; indexJ<columns; indexJ++){
			matrix[indexI][indexJ] = 0;
		}
	}
}

void multiplyMatrix(float resultMatrix[linhasA][colunasB],float a[linhasA][colunasA], float b[linhasB][colunasB]){
	int indexJ, indexI, indexK, aux;
	for(indexI = 0; indexI<linhasA; indexI++){
		for(indexJ = 0; indexJ<colunasB; indexJ++){
			aux = 0;
			for(indexK = 0; indexK<linhasB; indexK++){
				aux+=a[indexI][indexK]*b[indexK][indexJ];
			}
			resultMatrix[indexI][indexJ] = aux;
		}
	}
}

void printMatrix(int lines, int columns, float matrix[lines][columns]){
	int indexI, indexJ;
	for(indexI = 0; indexI<lines; indexI++){
		for(indexJ = 0; indexJ<columns; indexJ++){
			printf("\nElemento[%d][%d]: %0.3f", indexI, indexJ, matrix[indexI][indexJ]);
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	float a[linhasA][colunasA]; 
	float b[linhasB][colunasB];
	float c[linhasA][colunasB];

	if(colunasA != linhasB){
		printf("Error! A quantidade de linhas da matriz A deve ser igual à de colunas de B\n");
		return 0;
	}

	annulMatrix(linhasA, colunasB, c);
	inputMatrixData('A', linhasA, colunasA, a);
	inputMatrixData('B', linhasB, colunasB, b);
	multiplyMatrix(c, a, b);
	printMatrix(linhasA, colunasB, c);

	return 0;
}