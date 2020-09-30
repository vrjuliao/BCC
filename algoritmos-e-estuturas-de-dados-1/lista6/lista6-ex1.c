#include <stdio.h>
#include <stdlib.h>

int minutos(int *horario){
	return ((*horario) * 60) + *(horario+1);
}

int diferencaMinutos(int *maiorHorario, int *menorHorario){
	return minutos(maiorHorario) - minutos(menorHorario);
}
int main(int argc, char *argv[]){
	//horario[0]:horas
	//horario[1]:minutos
	//horario[2]:segundos
	int horario1[2], horario2[2];

	printf("--- Horario 1 --- \n");
	printf("Horas: ");
	scanf("%d", &horario1[0]);
	printf("Minutos: ");
	scanf("%d", &horario1[1]);

	printf("\n--- Horario 2 --- \n");
	printf("Horas: ");
	scanf("%d", &horario2[0]);
	printf("Minutos: ");
	scanf("%d", &horario2[1]);

	int diferencaHorario;
	diferencaHorario = diferencaMinutos(horario2, horario1);

	printf("\nDiferença em minutos entre horarios: %d\n", diferencaHorario);
	return 0;
}