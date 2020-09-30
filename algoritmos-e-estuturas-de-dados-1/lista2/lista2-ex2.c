#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	printf("Digite os segundos\n");
	int totalSegundos;
	scanf("%d", &totalSegundos);

	int totalMinutos;
	totalMinutos = totalSegundos/60;

	int totalHoras;
	totalHoras = totalMinutos/60;

	int minutos;
	minutos = totalMinutos%60;

	int segundos;
	segundos = totalSegundos%3600;

	printf("\n%dh %dmin %ds", totalHoras, minutos, segundos);
	return 0;
}