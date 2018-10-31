#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	int x;
	short int y;
	unsigned char a;

	//atribuindo os valores maximos para cada tipo de variavel e seus respectivos tamanhos
	x = pow(2, 31) - 1;
	y = pow(2, 15) - 1;
	a = pow(2, 8) - 1;

	printf("===== VALORES MAXIMOS =====\n");
	printf("int x = %d\n", x);
	printf("shotrt int y = %d\n", y);
	printf("unsigned char a = %c\n", a);

	//somando 1 em cada variavel
	x++;
	y++;
	a++;
	printf("\n\n===== VALORES MAXIMOS++ =====\n");
	printf("int x = %d\n", x);
	printf("short int y = %d\n", y);
	printf("unsigned char a = %c\n", a);
	return 0;
}