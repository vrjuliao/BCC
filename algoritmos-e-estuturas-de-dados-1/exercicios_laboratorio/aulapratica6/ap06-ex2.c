#include <stdio.h>
#include <stdlib.h>


#define N 3

void vetormatriz(double v[], double A[][N]){
	int indexI, indexJ, length;
	length = sizeof(v)/sizeof(int);
	for(indexI = 0; indexI<length; indexI++){
		for(indexJ = 0; indexJ<N; indexJ++){
			A[indexI][indexJ] = v[indexI+indexJ];
		}
	}
}