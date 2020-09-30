#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_INITIAL 3


typedef struct specialties{
	char *name;
	char *initial;
} SPECIALTIES;

SPECIALTIES *readScpecialtie(FILE *file, int *count){
	SPECIALTIES *sp;
	sp = NULL;
	char name[MAX_NAME], initial[MAX_INITIAL];
	while(!feof(file)){
		(*count)++;
		sp = (SPECIALTIES *) realloc(sp, ((*count)-1)*sizeof(SPECIALTIES));
		fscanf(file, "%s", name);
		fscanf(file, "%s", initial);
		sp[*count-1].name = name;
		sp[*count-1].initial = initial;
		// printf("%s\n%s\n", sp[*count-1].initial, sp[*count-1].name);
	}
	return sp;
}



int main(int argc, char const *argv[]){
	FILE *file;
	file = fopen("specialties.txt", "r");

	if(file == NULL || file == 0){
		printf("Erro na abertura do arquivo");
		return 0;
	}
	SPECIALTIES *currentSp;
	currentSp = NULL;
	int countSp;
	countSp = 0;
	currentSp = readScpecialtie(file, &countSp);

	system("clear");

	free(currentSp);
	fclose(file);
	return 0;
}