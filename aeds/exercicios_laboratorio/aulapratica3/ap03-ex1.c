#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

	int lines;
	while(1){
		printf("Digite o numero de linhas: ");
		scanf(" %d", &lines);
		if(lines > 0) break;
		else printf("Digite um valor válido!\n\n");
	}

	int index;
	int columns;
	int number;
	number = 1;
	for(index = 1; index <= lines; index++){
		for(columns = 1; columns <= index; columns++){
			printf("%d ", number);
			number++;
		}
		printf("\n");
	}
	return 0;
}