#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	printf("Digite dois valores inteiros\n");
	int valueA, valueB;
	scanf("%d%d", &valueA, &valueB);

	printf("\n%d+%d = %d", valueA, valueB, valueA + valueB);
	printf("\n%d-%d = %d", valueA, valueB, valueA - valueB);
	printf("\n%d*%d = %d", valueA, valueB, valueA * valueB);
	printf("\n%d/%d = %f", valueA, valueB, (float)valueA / valueB);
	printf("\nResto da divisão de %d por %d = %d", valueA, valueB, valueA % valueB);
	return 0;
}