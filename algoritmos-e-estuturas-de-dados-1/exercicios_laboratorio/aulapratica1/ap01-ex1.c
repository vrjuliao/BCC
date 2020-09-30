#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main(int argc, char *argv[]){
	double graus;
	double resultado;
	graus = 30.0;
	resultado = sin(graus * PI / 180);
	printf("O valor do seno = %lf\n", resultado);
	return 0; 
}