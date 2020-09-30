#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	printf("Digite um numero real:\n");
	float realNumber;
	scanf("%f", &realNumber);

	int integerPiece;
	integerPiece = (int) realNumber;

	float fractionalPiece;
	fractionalPiece = realNumber - integerPiece;

	printf("\nInteger piece: %d\nFractional piece:%f\n",integerPiece, fractionalPiece);
	return 0;
}